# Etch n Sketch

While playing around with curses on my Macbook, I decided to create a simple program that allows the users to draw in a terminal window with '0' characters. Unlike a traditional etch_n_sketch toy, you can also activate an eraser with the 'r' key. The drawing is cleared with the 'c' key. Quit by pressing 'q'.

As of creating this, I am using:

zsh 5.7.1 (x86_64-apple-darwin19.0)

I am not sure how curses behaves with other shells, but I may test with bash in the future.


Feel free to download my code, try it yourself, and make improvements. You can compile with:
> gcc -lncurses -o <*output file name*> etch_n_sketch.c

Then run with:
> ./etch_n_sketch


Have fun!