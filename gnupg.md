# Reproducing GnuPG 1.4.13 (FLUSH+RELOAD)

## Environment

- OS: WSL (Windows Sub Linux) in Kali Linux
- Kernel: 4.4.0-18362-Microsoft

## Install Dependencies

```
sudo apt install gcc-multilib
```

## Compile the GnuPG 1.4.13

- Download and extract the source code

```
cd ~
curl -O https://gnupg.org/ftp/gcrypt/gnupg/gnupg-1.4.13.tar.gz
tar -zxvf gnupg-1.4.13.tar.gz
```
- Compile the GnuPG through make
```
./configure
make
```
- The compiled file will locate at `~/gnupg-1.4.13/g10/gpg`

## Create the Scenario

- Generate a public key

```
cd ~
mkdir gnupg_home
chmod 777 ./gnupg_home
export GNUPGHOME="~/gnupg_home"
~/gnupg-1.4.13/g10/gpg --gen-key
```
- Select the following:
```
    - RSA and RSA
    - 2048
    - Never expires
```

- Input information (username, comment, email)

```
Test Key
test
test@test.com
```

- A example of console output:

```
gpg (GnuPG) 1.4.13; Copyright (C) 2012 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Please select what kind of key you want:
   (1) RSA and RSA (default)
   (2) DSA and Elgamal
   (3) DSA (sign only)
   (4) RSA (sign only)
Your selection? 1
RSA keys may be between 1024 and 4096 bits long.
What keysize do you want? (2048)
Requested keysize is 2048 bits
Please specify how long the key should be valid.
         0 = key does not expire
      <n>  = key expires in n days
      <n>w = key expires in n weeks
      <n>m = key expires in n months
      <n>y = key expires in n years
Key is valid for? (0)
Key does not expire at all
Is this correct? (y/N) y

We need to generate a lot of random bytes. It is a good idea to perform
some other action (type on the keyboard, move the mouse, utilize the
disks) during the prime generation; this gives the random number
generator a better chance to gain enough entropy.
..+++++
...............+++++
We need to generate a lot of random bytes. It is a good idea to perform
some other action (type on the keyboard, move the mouse, utilize the
disks) during the prime generation; this gives the random number
generator a better chance to gain enough entropy.
+++++
...+++++
gpg: /home/liuzongdong/testconf_gpg/trustdb.gpg: trustdb created
gpg: key 2B2A6F1D marked as ultimately trusted
public and secret key created and signed.

gpg: checking the trustdb
gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model
gpg: depth: 0  valid:   1  signed:   0  trust: 0-, 0q, 0n, 0m, 0f, 1u
pub   2048R/2B2A6F1D 2020-04-02
      Key fingerprint = 6D27 E8BA A905 6BE2 EDC5  12EF EDD5 6D68 2B2A 6F1D
uid                  Test Key (test) <test@test.com>
sub   2048R/B68B58D6 2020-04-02
```
- Encrypt a test messagge

```
cd ~
mkdir encryption
echo "Hello World" > ~/encryption/encryption.txt
~/gnupg-1.4.13/g10/gpg -r "Test Key" -e ~/encryption/encryption.txt
```

- To decrypt the messages, this step requires the  

```
~/gnupg-1.4.13/g10/gpg -d ~/encryption/encryption.txt
```
