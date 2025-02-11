# 🚀 NotifyLink
Receive **PRTG alerts** as Windows notifications across your network with ease.

## 📝 About This Project
NotifyLink is a **lightweight C++ application** that allows you to send notifications from **one computer to another** over a network.

### 📌 Why Did I Build This?
I use **PRTG** for network monitoring, but I wanted to receive notifications as **Windows notifications** instead of **SMS or email**.  
Not only on **my own computer**, but also on other **network specialists' computers**—not all users.

For simplicity, I chose to use [SnoreToast](https://github.com/KDE/snoretoast) instead of the [Windows API](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/), as the latter was too bulky.

---

## 📦 Project Structure
This repository contains **two main applications**:

1️⃣ **`NotificationReceiver` (Client-side)**
   - Runs on network clients.
   - Listens for messages from the server.
   - Displays received messages as Windows notifications.

2️⃣ **`NotificationSender` (Server-side)**
   - Runs on the PRTG server or any computer monitoring the network.
   - Sends alerts to all connected clients when an issue is detected.
   - Receives parameters from PRTG and forwards them to clients.

---

## 🔧 Installation & Setup

### 1️⃣ Clone the Repository  
```sh
git clone https://github.com/YourUsername/NotifyLink.git
cd NotifyLink
```
### 2️⃣ Modify Paths in NotificationReceiver
Before running the receiver, update the SnoreToast paths in the source code:
```
std::string command = "powershell.exe -Command \"& { Start-Process 'C:\\SnotreToast-EXE\\SnoreToast.exe' -ArgumentList '-t \\\"PRTG Notification\\\" -m \\\"" + message + "\\\" -p \\\"C:\\SnotreToast-EXE\\Pictures\\PRTG-logo.png\\\"' }\"";
```
Update:
`C:\\SnotreToast-EXE\\SnoreToast.exe`
`C:\\SnotreToast-EXE\\Pictures\\PRTG-logo.png`
Alternatively, use the official SnoreToast repository.
## 🚀 How to Run
### 1️⃣ Start the NotificationReceiver
Run the receiver software on the client machines:

Open Visual Studio, load the project, and run it.
Or build the project and run the generated Exe file.
### 2️⃣ Send a Notification using NotificationSender
While NotificationReceiver is running, execute the sender with PowerShell:
```
.\NotificationSender.exe "Your Message1" "Your Message2" "Your Message3" 192.168.1.1 192.168.1.2 192.168.1.3 ...
```
# Tasks
 - [ ] Dynamic `SnoreToast.exe` folder path and `logo` (Read from config.ini)
 - [ ] Use CMAKE for this project
