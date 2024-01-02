# Demo video
[<img src="https://github.com/beatrmatrix/beatrmatrix-stepsequencer/assets/155435444/e2875924-2747-43c7-a839-e10e0893d5e8" width="100%">](https://youtu.be/UGjb02PYg5U)
# Functions
- Supports 8 different MIDI sounds, enabling the triggering of diverse drums or samples loaded into a drum rack.
- Allows effortless creation and switching between 3 distinct patterns.
- Each pattern consists of 16 steps, with the option to link two patterns for a 32-step sequencer.
- Adjustable tempo, capable of halving the speed, ideal for handling longer samples.
- Visual feedback through RGB (ws2812b) LEDs, indicating MIDI sound and step positions.
- Dedicated buttons for placing individual sounds or samples on each step.
- Compact design, measuring under 0.5cm tall, 12.8cm long, and 8cm wide.

# How it works
The beatrmatrix device is simply a controller for the Max patcher. All the "magic" happens within the patcher.
![Artboard 1](https://github.com/beatrmatrix/beatrmatrix-stepsequencer/assets/155435444/69ccd0b2-98da-4127-9b73-ca75df1196e0)

# Parts
- PCB
- Arduino nano
- 4x WS2812 – 8 bit
- 19x 6x6x5mm tact push button
- some short wires
- thick double sided adhesive tape

# How to build it 
Placing the Arduino and buttons is straightforward. When it comes to the LEDs, it's a bit trickier. First, attaching side of double-sided tape to the WS2812 module. Then, solder the shorter wires to the necessary pins on the LED module. Next, attach the module onto the main PCB using the other side of the tape and proceed to solder the wires to the board.

<p>
<img src="https://github.com/beatrmatrix/beatrmatrix-stepsequencer/assets/155435444/bb9c64b8-949a-4c15-bf83-bc98acf3dd76" width="30%">
 <em>Pinout on the board for the ws2812 module</em>
</p>

# If you'd rather not build it yourself, you can order it on Etsy
Official Etsy shop: (https://www.etsy.com/shop/beatrmatrix)


# Support the project

| Paypal |
| ---- |
| [<img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" width="100%">](https://www.paypal.com/donate/?hosted_button_id=DY3BFYHC33TGG) |


