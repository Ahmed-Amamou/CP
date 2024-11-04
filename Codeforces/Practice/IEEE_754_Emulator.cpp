#include <bits/stdc++.h>
using namespace std;

// Union to help with bit manipulation of float
union FloatBits
{
    float f;
    uint32_t i;
};

class IEEE754Calculator
{
private:
    static constexpr uint32_t SIGN_MASK = 0x80000000;
    static constexpr uint32_t EXP_MASK = 0x7F800000;
    static constexpr uint32_t FRAC_MASK = 0x007FFFFF;

    vector<uint32_t> values;    // Store all computed values as raw bits
    vector<vector<float>> luts; // Store all LUT tables

    bool isNaN(uint32_t x)
    {
        return ((x & EXP_MASK) == EXP_MASK) && (x & FRAC_MASK);
    }

    bool isInf(uint32_t x)
    {
        return ((x & EXP_MASK) == EXP_MASK) && !(x & FRAC_MASK);
    }

    uint32_t extractBits(uint32_t num, int start, int len)
    {
        uint32_t mask = ((1U << len) - 1) << (start - len + 1);
        return (num & mask) >> (start - len + 1);
    }

    // Pure bitwise NAND operation
    uint32_t nandOperation(uint32_t a, uint32_t b)
    {
        return ~(a & b);
    }

    // FMA operation now works with raw bits
    uint32_t fmaOperation(uint32_t a, uint32_t b, uint32_t c)
    {
        FloatBits fa{.i = a};
        FloatBits fb{.i = b};
        FloatBits fc{.i = c};

        // Handle special cases
        if (isNaN(a) || isNaN(b) || isNaN(c))
        {
            return 0x7fc00000; // NaN
        }

        bool aInf = isInf(a), bInf = isInf(b), cInf = isInf(c);
        bool aZero = (a & ~SIGN_MASK) == 0;
        bool bZero = (b & ~SIGN_MASK) == 0;

        // 0 × ∞ → NaN
        if ((aZero && bInf) || (bZero && aInf))
        {
            return 0x7fc00000;
        }

        float result = fmaf(fa.f, fb.f, fc.f);
        FloatBits res{result};
        return res.i;
    }

public:
    void init(uint32_t initial_value)
    {
        values.clear();
        luts.clear();
        values.push_back(initial_value);
    }

    void addLUT(const vector<float> &table)
    {
        luts.push_back(table);
    }

    uint32_t executeCommand(const string &cmd, const vector<int> &params, uint32_t hex_value = 0)
    {
        uint32_t result;

        if (cmd == "L")
        { // LUT command
            int lut_idx = params[0];
            int start_bit = params[1];
            int bit_len = params[2];

            uint32_t mask = extractBits(values[0], start_bit + bit_len - 1, bit_len);
            FloatBits fb{luts[lut_idx][mask]};
            result = fb.i;
        }
        else if (cmd == "N")
        { // NAND command
            result = nandOperation(values[params[0]], values[params[1]]);
        }
        else if (cmd == "F")
        { // FMA command
            result = fmaOperation(values[params[0]], values[params[1]], values[params[2]]);
        }
        else if (cmd == "C")
        { // Constant command
            result = hex_value;
        }

        values.push_back(result);
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    IEEE754Calculator calc;

    while (T--)
    {
        string initial_hex;
        cin >> initial_hex;
        uint32_t initial_value = stoul(initial_hex, nullptr, 16);

        calc.init(initial_value);

        // Read LUTs
        int L;
        cin >> L;
        for (int i = 0; i < L; i++)
        {
            int size;
            cin >> size;
            vector<float> table(size);
            for (int j = 0; j < size; j++)
            {
                string hex;
                cin >> hex;
                FloatBits fb;
                fb.i = stoul(hex, nullptr, 16);
                table[j] = fb.f;
            }
            calc.addLUT(table);
        }

        // Process commands
        int Q;
        cin >> Q;
        uint32_t final_result;

        for (int i = 0; i < Q; i++)
        {
            string cmd;
            cin >> cmd;

            if (cmd == "L")
            {
                int lut_idx, start_bit, bit_len;
                cin >> lut_idx >> start_bit >> bit_len;
                final_result = calc.executeCommand(cmd, {lut_idx, start_bit, bit_len});
            }
            else if (cmd == "N")
            {
                int idx1, idx2;
                cin >> idx1 >> idx2;
                final_result = calc.executeCommand(cmd, {idx1, idx2});
            }
            else if (cmd == "F")
            {
                int idx1, idx2, idx3;
                cin >> idx1 >> idx2 >> idx3;
                final_result = calc.executeCommand(cmd, {idx1, idx2, idx3});
            }
            else if (cmd == "C")
            {
                string hex;
                cin >> hex;
                final_result = calc.executeCommand(cmd, {}, stoul(hex, nullptr, 16));
            }
        }
        cout << hex << setfill('0') << setw(8) << final_result << dec << "\n";
    }

    return 0;
}