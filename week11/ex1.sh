fallocate -l $((51*1024*1024)) lofs.img
sudo losetup /dev/loop8 lofs.img
sudo mkfs -t ext4 /dev/loop8
mkdir lofsdisk
sudo mount -t ext4 lofs.img ./lofsdisk

