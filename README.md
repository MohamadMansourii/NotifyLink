# NotifyLink
Send PRTG alerts as Windows notifications across your network with ease.

Recently, I developed a C++ application to send notifications from one computer to another over the network.
(I wanted to receive Windows notifications instead of SMS or email from PRTG, which I use for network monitoring. Not just on my own computer, but also on other computers in the network—specifically, only on the computers of network specialists, not all users.)

In the end, I decided to use [SnoreToast](https://github.com/KDE/snoretoast) instead of the [Windows API](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/), as the latter was too bulky.

### This repository includes two code snippets that work together:
+ The first snippet runs on network clients and waits to receive messages from the server to display to the user.
+ The second snippet is installed on the server or the computer running PRTG. In case of any issues with network switches or other parts of the network, it sends alerts to all clients. Essentially, it’s a tool that, when executed, receives parameters from PRTG and forwards them to the network clients.

## How to run this project in your computer
> [!WARNING]  
> You must change these addresses to run SnoreToast in the `NotificationReceiver` source code.
> ```Cpp
> std::string command = "powershell.exe -Command \"& { Start-Process 'C:\\SnotreToast-EXE\\SnoreToast.exe' -ArgumentList '-t \\\"PRTG Notification\\\" -m \\\"" + message + "\\\" -p \\\"C:\\SnotreToast-EXE\\Pictures\\PRTG-logo.png\\\"' }\"";
> ```
> `C:\\SnotreToast-EXE\\SnoreToast.exe` and `C:\\SnotreToast-EXE\\Pictures\\PRTG-logo.png`
> 
> The files required to run the [SnoreToast](https://github.com/KDE/snoretoast) tool are also included in this repository, which you can use. Alternatively, you can use the ones from the original SnoreToast repository.

You need to run the `NotificationReceiver` software on your system. You can use Visual Studio to open and run the program code, or even build it and use the generated executable (Exe) file.

While the `NotificationReceiver` application is running, to use the `NotificationSender` software, you should use PowerShell. In the path of the EXE file of this software, you can test the software by executing the following command in PowerShell.
```Bash
 .\ConsoleApplication2.exe "Your Message1" "Your Message2" "Your Message3" 192.168.1.1 192.168.1.2 192.168.1.3 ...
```
