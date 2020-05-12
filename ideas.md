Brainstorming
=============

- AFL suggested filetype:
  - images: bmp, gif, ico, jp2, jpeg, jxr, png, tiff, webp
  - multimedia: h264 mp4
  - others: elf, js, pcap, pdf, regexp, rtf, sql, text, xml

Based on the ideas of AFL, a auto fuzzing tool.

- What is *theoretically* possible, assuming the attacker gets perfect knowledge of all branches
  - Automate the process of finding out what an attacker could learn.

- Attack a PDF renderer. Seems like a good case where FLUSH + RELOAD could hook some of the rendering functions and learn what the PDF looks like (font loading, etc). (AFL works fine with PDF file)

- Attack a Image renderer (AFL works fine with a lot of images)

- Attack a Web Browser (AFL works fine with js)

- Attack programs of different kinds:
  - Compression (tar, gzip, bzip, 7z, zip, etc.)
  - SSH (the crypto parts as well as non-crypto parts).
    - Server
    - Client
  - Web server, mail server, DNS server, FTP server
  - Shells (bash, zsh, etc.)
  - Standard system utilities (ls, cat, dd, etc.)

- Scripting languages?
  - Python (Most familiar)
  - Java (Most familiar)
  - C / C++ (Just so-so)
  - Ruby (A lot of applications running on the Ruby, totally new language, I have no idea about it)

- Virtual machines
  - Probe the virtual machine software itself, might reveal a lot of
    information about what another user's VM is doing.

- Evaluate the *actual* limitations of FLUSH + RELOAD.
  - Where exactly does the noise come from ??? Because sometimes the spy program will be triggered by even a mouse click or move of the application windows, and it is really sucks.

- Is it possible to attach FLUSH+RELOAD to a *lot* of things, like libc, or a lot of different executables at the same time? So we just collect massive data set, exfiltrate it, then analyse it offline?
