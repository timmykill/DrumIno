# DrumIno

#Usage

CHROMIUM
$ chromium --enable-logging --v=0 --user-data-dir=temp-dir  index.html
$ cat temp-dir/chrome_debug.log | cut -d\" -f2

SERIAL STUFF
# stty -F /dev/ttyACM0 cs8 9600 ignbrk -brkint -icrnl -imaxbe -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke nofls -ixon -crtscts



#To do
Sanitazing most of the code, currently ugly as hell.
