sudo cp ex2.c lofsdisk/
cd lofsdisk/
sudo gcc ex2.c -o ex2.out
sudo echo "Anatoliy" > file1.txt
sudo echo "Shvarts" > file2.txt
sudo mkdir bin
sudo mkdir lib64
sudo cp /bin/bash ./bin
sudo cp /bin/ls ./bin
sudo cp -v /lib/x86_64-linux-gnu/libtinfo.so.6 /lib/x86_64-linux-gnu/libdl.so.2 /lib/x86_64-linux-gnu/libc.so.6 /lib64/ld-linux-x86-64.so.2 ./lib64/
sudo cp -v /lib/x86_64-linux-gnu/libselinux.so.1 /lib/x86_64-linux-gnu/libc.so.6 /lib/x86_64-linux-gnu/libpcre2-8.so.0 /lib/x86_64-linux-gnu/libdl.so.2 /lib64/ld-linux-x86-64.so.2 /lib/x86_64-linux-gnu/libpthread.so.0 ./lib64/
sudo cp -r ./lib64 ./lib
cd ..
chroot ./lofsdisk/ /bin/bash <<END
./ex2.out
END
