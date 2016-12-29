# Lixie Serial Parser
Connor Nishijima (2016)

**This is code for parsing commands sent over Serial UART!**

To control Lixies using a microcontroller as a Serial UART bridge, you need to send UART commands like this:

    2:0:255:0\n // set color_on_rgb to GREEN
    3:0:0:0\n   // set color_off_rgb to BLACK
    1:123\n     // write_int: 123
    
This will display "123" on the displays in green!

# Usage

Flash the Lixie_Serial_Parser.ino sketch to your controller, and it will wait for a command!
Any programming language that can write to a UART at 115200 baud can use this gateway to controlling Lixies. Just print a command:

I've included a Python example directory perfect for embedded computers like the Raspberry Pi, which uses an easy lix.begin(), 
clear() and write() library you can import to your own scripts! Tested speed is over 100 FPS!

For example, printing the UNIX epoch time (in magenta) using the lixie.py library:

    import lixie as lix
    import time
    
    # Clear displays
    lix.begin()
    
    # Set color to magenta
    lix.color_on_rgb(255,0,255)
    
    while True:
        lix.write( int(time.time()) )
        
        # Wait for one second
        time.sleep(1)
