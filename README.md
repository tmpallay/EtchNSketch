# Etch n Sketch

While playing around with curses on my Macbook, I decided to create a simple program that allows the user to draw in a terminal window with different characters. Unlike a traditional etch_n_sketch toy, you can also activate an eraser mode. You also have the option of drawing with different characters.

### Controls

* arrow keys	-	Move the curser and draw
* r 			- 	toggle eraser
* c 			-	clear drawing
* p 			-	press this key and then press the key of the desired character to draw with. The default character is '0'
* q 			-	quit

### Notes

As of creating this, I am using:

zsh 5.7.1 (x86_64-apple-darwin19.0)

I am not sure how curses behaves with other shells, but I may test with bash in the future.

Feel free to download my code, try it yourself, and make improvements. You can compile with:

```(zsh)
gcc -lncurses -o <*output file name*> etch_n_sketch.c
```

Then run with:

```(zsh)
./etch_n_sketch
```

Have fun!