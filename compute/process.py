# Code to do the processing of wrong posture across a timeframe

import csv, serial

# initializing some stuff
ser = serial.Serial("/dev/ttyACM0")
csvfile = open("data.csv", 'wb')
csvwriter = csv.writer(csvfile, delimiter = ',', quotechar='"', quoting = csv.QUOTE_MINIMAL)
csvwriter.writerow(["sl_no", "flexVal", "buzzed"])

num = 1 # reference value for first reading
counter = 0 # initial value of counter
limit = 10 # tolerance value for counter
threshold = 410 # threshold value, below this we should buzz

# main program loop
while(ser.isOpen()):
  val = int(ser.readline()[:3])
  # track the bad posture
  if(val < threshold):
    counter = counter + 2
    
    # if the bad posture is prolonged, send the buzz
    if(counter > limit):
      ser.write("1")
      csvwriter.writerow([num, val, 1])
      counter = 0
    else:
      csvwriter.writerow([num, val, 0])
  # if the posture is good, then reverse the effect of bad posture
  else:
    if(counter > 0):
      counter = counter - 1
    csvwriter.writerow([num, val, 0])
  num =  num + 1

ser.close()
