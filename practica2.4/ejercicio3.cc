mkfifo pipe
echo 12345 > pipe

Y en otro terminal:

cat pipe
