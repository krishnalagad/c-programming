# Install VS Code, GCC, G++ in Ubuntu using Terminal
```bash
sudo apt update --fix-missing
sudo apt install  gcc  g++
sudo snap install code --classic

```

# change c++ compiler
```bash
nano ~/.bashrc 
alias g++='-std=c++17'
```