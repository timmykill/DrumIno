# DrumIno

##Usage
chromium --enable-logging --v=0 --user-data-dir=temp-dir  index.html
cat temp-dir/chrome_debug.log | cut -d\" -f2
