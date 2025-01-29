# NotifyLink
Send PRTG alerts as Windows notifications across your network with ease.

Recently, I developed a C++ application for sending notifications from one computer to another over the network.
(I wanted to receive Windows notifications instead of SMS or email from PRTG, which I use for network monitoring. And not just on my own computer, but on other computers on the network as well—specifically, only the computers of the network specialists, not all users.)

In the end, I decided to use [SnoreToast](https://github.com/KDE/snoretoast) instead of the [Windows API](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/), which was too bulky.

### This repository includes two code snippets that work together:
+ The first snippet runs on the network clients, waiting to receive a message from the server to display to the user.
+ The second snippet is installed on the server or the computer running PRTG. In case of any issues with network switches or other parts of the network, it sends alerts to all clients. Essentially, it’s a tool that, upon execution, receives parameters from PRTG and sends them to the network clients."
