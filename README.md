# TouchDesignerToLEDs
A sample project to show how to take a TOP in TouchDesigner and send it via UDP to an arduino controlling WS2812B strips.

This sends via UDP as I find it nicer to send data over Cat-7 for longer distances. This was tested with the following kit:
- 1x Arduino Mega
- 1x Arduino Mega Ethernet Shield (v2.0, not v1.0)
- 5x 1M (1cm per pixel) WS2812B LED strips
- 1x 5V LED Power Supply
- 1x 20M CAT-7 Cable

All in all the whole kit costed about 12,000 yenn from AliExpress and Akihabara.

### Things to Note

UDP has a maximum send limit so you can only control up to 500 LEDs with one UDP packet.
This is easily enough avoided by sending the data as 2 packets and then filling the LED arrays separately.

### Using this setup with SimpleMixer

You can download the Fucksleep show I did for Club Mago in Nagoya as an example by switching to SimpleMixers "Fucksleep" branch.

![SimpleMixer Fucksleep Branch](Images/SimpleMixer-Fucksleep.jpg?raw=true "SimpleMixer Fucksleep Branch")
