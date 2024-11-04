/*
 ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▀▀▄   ▄▀▀█▄▄
█  █   ▄▀ ▐ ▄▀ ▀▄ █  █ ▀  █ █      █ █      █ █ ▄▀   █
▐  █▄▄▄█    █▄▄▄█ ▐  █    █ █      █ █      █ ▐ █    █
   █   █   ▄▀   █   █    █  ▀▄    ▄▀ ▀▄    ▄▀   █    █
  ▄▀  ▄▀  █   ▄▀  ▄▀   ▄▀     ▀▀▀▀     ▀▀▀▀    ▄▀▄▄▄▄▀
 █   █    ▐   ▐   █    █                      █     ▐
 ▐   ▐            ▐    ▐                      ▐
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

using namespace std;
#define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

#include <sstream>


struct Event
{
    string eventId;
    string title;
    string acronym;
    string projectCode;
    string threeDigitCode;
    string recordType;
    string parentId; // For child events

    bool operator<(const Event &other) const
    {
        if (title != other.title)
            return title < other.title;
        return eventId < other.eventId;
    }
};

// Structure to represent a conference series
struct ConferenceSeries
{
    Event parent;
    vector<Event> children;
};

class ConferenceProcessor
{
private:
    map<string, ConferenceSeries> conferencesByAcronym;

    // Split CSV line into fields
    vector<string> splitCSV(const string &line)
    {
        vector<string> fields;
        string field;
        bool inQuotes = false;
        ostringstream currentField;

        for (size_t i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if (c == '"')
            {
                if (i + 1 < line.length() && line[i + 1] == '"')
                {
                    // Handle escaped quotes
                    currentField << '"';
                    i++;
                }
                else
                {
                    inQuotes = !inQuotes;
                }
            }
            else if (c == ',' && !inQuotes)
            {
                fields.push_back(currentField.str());
                currentField.str("");
                currentField.clear();
            }
            else
            {
                currentField << c;
            }
        }
        fields.push_back(currentField.str());
        return fields;
    }

    // Parse a line into an Event structure
    Event parseEvent(const string &line)
    {
        auto fields = splitCSV(line);
        Event event;
        event.eventId = fields[0];
        event.title = fields[1];
        event.acronym = fields[2];
        event.projectCode = fields[3];
        event.threeDigitCode = fields[4];
        event.recordType = fields[5];
        return event;
    }

    // Check if all children have the same three digit code
    string determineParentThreeDigitCode(const vector<Event> &children)
    {
        if (children.empty())
            return "";

        string firstCode = children[0].threeDigitCode;
        for (const auto &child : children)
        {
            if (child.threeDigitCode != firstCode)
            {
                return "???";
            }
        }
        return firstCode;
    }

public:
    void processInput()
    {
        string line;
        map<string, vector<Event>> childrenByParentAcronym;
        map<string, Event> parentEvents;

        // Read and process each line
        while (getline(cin, line))
        {
            Event event = parseEvent(line);

            // Skip events without acronym
            if (event.acronym.empty())
                continue;

            if (event.recordType == "Parent Event")
            {
                // Store parent event
                if (parentEvents.find(event.acronym) != parentEvents.end())
                {
                    // Duplicate parent found - markih
                    parentEvents[event.acronym].eventId = ""; 
                }
                else
                {
                    parentEvents[event.acronym] = event;
                }
            }
            else
            {
                // Store child event
                childrenByParentAcronym[event.acronym].push_back(event);
            }
        }

        // Process valid conference series
        for (const auto &parentPair : parentEvents)
        {
            const string &acronym = parentPair.first;
            Event parent = parentPair.second;

            // Skip if parent mouvh valid
            if (parent.eventId.empty())
                continue;

            // Skip if no children
            auto childrenIt = childrenByParentAcronym.find(acronym);
            if (childrenIt == childrenByParentAcronym.end() || childrenIt->second.empty())
            {
                continue;
            }

            // Create conference series
            ConferenceSeries series;
            series.parent = parent;
            series.children = childrenIt->second;

            // Set parent's three digit code
            series.parent.threeDigitCode = determineParentThreeDigitCode(series.children);

            // Set parent ID for children
            for (auto &child : series.children)
            {
                child.parentId = parent.eventId;
            }

            // Sort children
            sort(series.children.begin(), series.children.end());

            conferencesByAcronym[acronym] = series;
        }
    }

    void printOutput() const
    {
        for (const auto &pair : conferencesByAcronym)
        {
            const ConferenceSeries &series = pair.second;


            cout << series.parent.eventId << ","
                      << "\"" << series.parent.title << "\","
                      << "\"" << series.parent.acronym << "\","
                      << series.parent.projectCode << ","
                      << series.parent.threeDigitCode << ","
                      << "\"" << series.parent.recordType << "\"" << endl;

            for (const Event &child : series.children)
            {
                cout << child.eventId << ","
                          << "\"" << child.title << "\","
                          << "\"" << child.acronym << "\","
                          << child.projectCode << ","
                          << child.threeDigitCode << ","
                          << "\"" << child.recordType << "\","
                          << child.parentId << endl;
            }
        }
    }
};

signed main()
{
    FAST;
    ConferenceProcessor processor;
    processor.processInput();
    processor.printOutput();
    return 0;
}