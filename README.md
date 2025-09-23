# push_swap

Push_swap

Projenin amacı: Stack a’yı sınırlı bir komut seti ile minimum hamlede sıralamak.

Temel Yapılar: Projede a ve b adında iki stack kullanılır. Başlangıçta tüm sayılar a stackinde bulunur ve b stacki boştur. 

**Input **: tekrarsız, pozitif ya da negatif, integer sayılar. tek bir string içinde de verilebilir birden fazla argüman olarak da verilebilir.

örn: 

./a.out “ 2 1 3 6 “
./a.out 2 1 3 6
 
**Output **:  Verilen inputu artan sırada sıralamak için gerekli komutları yazdırır. 

örn:

./a.out 2 1 3 
sa

./a.out 3 2 1
sa 
rra  

Tercih edilen veri yapısı: Linked List.


**Neden Bağlı Liste (Linked List)?**
Proje özellikle linked list kullanımını şart koşmamaktadır. İstenirse array da kullanılabilir. Ancak komut setini incelediğimizde özellikle push a ve push b bakımından array kullanımı yavaş ve kullanışsız olacaktır.
 
Örneğin push b için:
array : a dizisinin başındaki elemanı aldıktan sonra tüm dizideki elemanları sola kaydırmamız gerekir. n sayı için n - 1 kadar işlem gerektirir. B dizisindeki tüm elemanları sağa kaydırıp yer açtığımızda da bu kaydırma işlemi keza m elemanlı bir dizi için m-1 adet işlem gerektirir. Çok yavaştır.

**linked list:** a listesinin başındaki düğümü al. Yeni başlangıcı ikinci düğüm yap. Aldığın düğümü b nin başına yönlendir. B listesinin yeni başlangıcını bu düğüm yap. Listenin eleman sayısı kaç olursa olsun bu işlem burada sadece 4 hamlede gerçekleşir. Arraye kıyasla çok hızlı sürer (O(1)).


