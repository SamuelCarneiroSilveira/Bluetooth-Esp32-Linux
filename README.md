# Como conectar via bluetooth

No terminal use esse comando para encontrar o mac adress do esp

```
bluetoothctl
power on
agent on
scan on
```
// NEW] Device D8:BC:38:E5:A2:F6 ESP_32
```
pair D8:BC:38:E5:A2:F6
```
// libera a porta antes de tentar a conexão
// sudo rfcomm release /dev/rfcomm0
// sudo rfcomm connect /dev/rfcomm0 D8:BC:38:E5:A2:F6 1 &
// o & é para jogar em segundo plano
```
sudo rfcomm bind rfcomm0 D8:BC:38:E5:A2:F6
```
Agora para visualizar o monitor bt serial 
```
sudo apt-get update
sudo apt-get install minicom
minicom -D /dev/rfcomm0 -b 115200
```
