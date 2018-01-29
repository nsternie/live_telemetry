import serial, sys, os, time

if(sys.argv[1] == "-h"):
	print("usage: "+sys.argv[0]+" COMXX baudrate [data folder override]")
	exit(0)

# Make data folder
cwd = os.getcwd()
if(len(sys.argv) == 4):
	datadir = cwd+"/data/"+sys.argv[3]
else:
	datadir = cwd+"/data/"+time.strftime("%Y_%m_%d_%H-%M-%S")
os.makedirs(datadir)

# Open Serial port
port = sys.argv[1]
baud = int(sys.argv[2])
try:
	ser = serial.Serial(port, baudrate=baud, timeout=1)
except:
	print("Could not open "+port)
	print("exiting...")
	exit(1)

