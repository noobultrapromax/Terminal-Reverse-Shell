> Generate Reverse Shell in terminal Blazingly Fast!!!
Automatically copy to clipboard and option to start listener of choice.

# Compile Instructions
```bash
# Clone this repo
https://github.com/noobultrapromax/Terminal-Reverse-Shell

# Compile the binary
g++ main.cpp -o tshell

# Make local bin directory 
mkdir ~/.local/bin -p

# Move Binary to bin directory
mv tshell ~/.local/bin 

# Add ~/.local/bin to $PATH by adding this to ~/.profile
if [ -d "$HOME/.local/bin" ] ; then
    PATH="$HOME/.local/bin:$PATH"
fi
```
Or just use the binary from releases

# To Do :
- [ ] Should be a compiled binary in C/C++
    - [ ]  Small and Fast
- [ ] TUI or not ?
    - [ ] VIM motion in TUI
- [ ] Option to URL encode
- [ ] Grab parameters from main
- [ ] Option to grab tun0 (VPN)/eth0/wlp0 IPv4
- [ ] Option to start a listener on local machine
- [ ] Add more Shells
- [ ] Check Ip format and Port Range
- [ ] Error Handling

# Credits:
https://pentestmonkey.net/cheat-sheet/shells/reverse-shell-cheat-sheet
