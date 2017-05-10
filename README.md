# DrumIno

DrumIno is the automatic electronic drummer which plays alone.
It is made of:
1 arduino leonardo
7 servomotors (1 for the crash cymbal, 2 for the snare drum, 2 for the charleston, 2 for the gable)
4 electromagnets
3 buttons (1 power button, 2 rhythm select)
1 led (blink in timo to the rhythm)

#Usage

CHROMIUM
$ chromium --enable-logging --v=0 --user-data-dir=temp-dir  index.html
$ cat temp-dir/chrome_debug.log | cut -d\" -f2

SERIAL STUFF
# stty -F /dev/ttyACM0 cs8 9600 ignbrk -brkint -icrnl -imaxbe -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke nofls -ixon -crtscts



#To do
Sanitazing most of the code, currently ugly as hell.
