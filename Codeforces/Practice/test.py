import os
import sys
from datetime import datetime

now = datetime.now()

current_time = now.strftime("%H:%M")
print("Current time is ",current_time)
current_time = current_time.split(":")

shutdown_time = input("Shutdown time: ")
shutdown_time = shutdown_time.split(":")

current_time = now.strftime("%H:%M")
current_time = current_time.split(":")

seconds=((int(shutdown_time[0])-int(current_time[0]))*60*60)+(int(shutdown_time[0])-int(current_time[0])*60)

if (seconds < 0 ):
  seconds = 0
try:
  os.system(f'shutdown /s /t {seconds}')
  cancel = input(f"System shutting down in {seconds} seconds.\nEnter 'Cancel' to abort, or press Enter to exit.")
except:
  input("Unexpected error:", sys.exc_info()[0], "\nPress Enter to exit.")
if(cancel=="Cancel"):
  os.system('shutdown /a')
  input("System shutdown cancelled.\nPress Enter to exit.")