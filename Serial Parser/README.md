# Lixie Serial Parser
Connor Nishijima (2016)

**This is code for parsing JSON commands sent over Serial UART!**

To control Lixies using a microcontroller as a USB Serial bridge, you need to send a command like this to the Serial port of the uC:

    {
      "number":**NUMBER_TO_SHOW**,
      "color_type":**COLOR_SPACE**,
      "on_color":[
        **COLOR_1**,
        **COLOR_2**,
        **COLOR_3**
      ],
      "off_color":[
        **COLOR_1**,
        **COLOR_2**,
        **COLOR_3**
      ]
    }
    
# Variables

**NUMBER_TO_SHOW** Obvious enough, right? (Can be int or float, or string)

**COLOR SPACE** Can be "RGB" or "HSV"

**COLOR_1/2/3** Can be RGB value, or HSV value, based on color space selected

# Usage

Flash the Lixie_Serial_Parser.ino sketch to your controller, and it will wait for a command!
Any programming language that can write to a USB Serial Port can use this gateway to controlling Lixies. Just print a command:

    {"number":42, "color_type":"RGB", "on_color":[0,255,255], "off_color":[0,0,0]}

This will display a cyan "42"!

I've included a Python example directory perfect for embedded computers like the Raspberry Pi, which uses an easy lixie.begin(), 
clear() and write() file you can import to your own scripts! The library does the job of appending a newline character ("\n") to your
command so you don't have to. Tested speed is about 100 FPS!

For example, printing the UNIX epoch time using the lixie.py library:

    import lixie
    import time
    
    # Clear displays
    lixie.begin()
    
    while True:
        # Prepare data
        data = {
            "number":int(time.time()),
            "color_type":"RGB",
            "on_color":[
                255,0,255
            ],
            "off_color":[
                0,0,0
            ]
        }
        # Write data
        lixie.write(data)
        
        # Wait for one second
        time.sleep(1)
