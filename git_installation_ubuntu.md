# Git Installation in Ubuntu using Terminal
```bash

sudo apt update

sudo apt install git

git --version

```

# Git SSH Key generation in Ubuntu using Terminal
```bash

ssh-keygen -t rsa -b 4096 -C "your_email@example.com"

eval "$(ssh-agent -s)"  # after this command add public key in your GitHub profile

```

# Clone remote Git repository using SSH
```bash
git clone <your_git_ssh_url>
```