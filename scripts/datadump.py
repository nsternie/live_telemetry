import serial, sys, os, time
import matplotlib.pyplot as plt
import time

if("-h" in sys.argv):
    print("usage: "+sys.argv[0]+" COMXX baudrate [data folder override] [flags]")
    print("Flags:")
    print("-s\t\tShow plots on exit")
    print("-h\t\tShow this help menu")
    print("-e\t\tShow easteregg")
    print("--code-red\tBegin self destruct sequence")
    exit(0)

def toobad(x,y):
    print("Hahaha, nice try, Dave... ;)")

if("-e" in sys.argv):
    os.system("start chrome parrot.gif")
    exit(0)
if("--code-red" in sys.argv):
    import signals
    signal.signal(signal.SIGINT, toobad)
    print("\n\nGoodbye, Dave.")
    print("You cannot stop this")
    n = 10
    while(n >= 0):
        print(n)
        n -= 1
        time.sleep(1)
    print("Lets get this party started!")
    os.system("start chrome https://www.youtube.com/watch?v=-22tna7KHzI")
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
    ser = serial.Serial(port, baudrate=baud, timeout=0.25)
    print("Connected on "+port+" at "+str(baud)+"bps")
except:
    print("Could not open "+port)
    print("exiting...")
    exit(1)

# Download all binaries from the flight computer
ser.write(b'numfiles \r')                        # Check how many files there are
response = int(ser.readline())                  #
print("There are "+str(response)+" files to read...")
filelist = []
for filenum in range(response):                 
    print("Downloading file "+str(filenum)+"...")    
    filename = datadir+"/"+str(filenum)+".bin"       
    filelist.append(filename)                   
    binfile = open(filename, "wb")              # Open the binary
    readfile = True                
    command_string = "pfr "+str(filenum)+" \r"             
    ser.write(bytes(command_string, 'ascii'))        # send "Print file raw" to fc
    while(readfile):                            
       try:                                     
         page = ser.read(2048)                  # Read a page
         if(len(page) != 2048):
            readfile = False
         binfile.write(page)                    # Log to bin
       except SerialTimeoutException:       # Read pages until the fc stops sending them
         readfile = False                       # Then move on to the next file
       except:
         print("Serial error")                  # Oops
         exit(1) 
    binfile.close()                             # Close bin file

print("All files downloaded.")                 
ser.close()                                     
print(port+" closed.")


# Convert each binary into a csv
for binfile in filelist:
    print("Converting "+binfile+"...", end='')
    csv_file = binfile.rstrip(".bin")+".csv"
    os.system("fc_bin2csv.exe "+str(binfile)+" > "+csv_file)
    print("Generating pdf...", end='')
    os.system("fc_autoplot "+csv_file)
    if("-s" in sys.argv):
        os.system("start chrome "+binfile.rstrip(".bin")+"_plots.pdf")
    print(" done.")

print("All files converted... Exiting")