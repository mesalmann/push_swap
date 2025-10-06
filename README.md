# push_swap

Push_swap

Projenin amacı: Stack a’yı sınırlı bir komut seti ile minimum hamlede sıralamak.

Temel Yapılar: Projede a ve b adında iki stack kullanılır. Başlangıçta tüm sayılar a stackinde bulunur ve b stacki boştur. 

Input : tekrarsız, pozitif ya da negatif, integer sayılar. tek bir string içinde de verilebilir birden fazla argüman olarak da verilebilir.

örn: 

./a.out “ 2 1 3 6 “
./a.out 2 1 3 6
 
Output :  Verilen inputu artan sırada sıralamak için gerekli komutları yazdırır. 

örn:

./a.out 2 1 3 
sa

./a.out 3 2 1
sa 
rra  

Tercih edilen veri yapısı: Linked List.


Neden Bağlı Liste (Linked List)?
Proje özellikle linked list kullanımını şart koşmamaktadır. İstenirse array da kullanılabilir. Ancak komut setini incelediğimizde özellikle push a ve push b bakımından array kullanımı yavaş ve kullanışsız olacaktır.
 
Örneğin push b için:
array : a dizisinin başındaki elemanı aldıktan sonra tüm dizideki elemanları sola kaydırmamız gerekir. n sayı için n - 1 kadar işlem gerektirir. B dizisindeki tüm elemanları sağa kaydırıp yer açtığımızda da bu kaydırma işlemi keza m elemanlı bir dizi için m-1 adet işlem gerektirir. Çok yavaştır.

linked list: a listesinin başındaki düğümü al. Yeni başlangıcı ikinci düğüm yap. Aldığın düğümü b nin başına yönlendir. B listesinin yeni başlangıcını bu düğüm yap. Listenin eleman sayısı kaç olursa olsun bu işlem burada sadece 4 hamlede gerçekleşir. Arraye kıyasla çok hızlı sürer (O(1)).




-------------------
Turk Algoritması

A yığınındaki tüm sayıları minimum hamleyle B’ye taşıyıp, ardından sıralı biçimde geri A’ya yerleştirmektir.<br>

1- İlk iki sayıyı B’ye gönder.<br>

while -- sizeof_stack_a != 3 {<br>
2- Sonraki atılacak sayı için A'daki tüm sayıların B'ye atılma maliyetini hesapla.<br>

Maliyet hesabı : <br>
a) Maliyeti hesaplanacak sayının B stackinde kendinden küçük en büyük sayıyı yoksa en büyük sayıyı bul. Yani match sayısını bul.<br>
b) Maliyeti hesaplanıcak sayıyı stackin en üstüne getirmek için gereken hamle sayısını hesapla.<br>
c) Match sayısını B stackinde en üste getirmek için gereken hamle sayısını hesapla<br>
d) Bunları topla ve +1 ekle (push b maliyeti için +1 eklenir).<br>

3- A stackinden B stackine atılmak için maliyeti en düşük olan sayı yani best_cost bulununca best_costu stackin en üstüne getir.<br>
4- Best_costun matchini B stackinde en üste getir.<br>
5- push b yap ve best_costu b stackinde matchinin üstüne pushla.<br>
}<br>
6- A stackinde 3 sayı kaldığı an döngü bitecek.<br>
7- Sort three fonksiyonuyla kalan 3 lüyü sırala.<br>
8- B stackindeki geri A ya pushlamamız gerekiyor. Gönderilecek sayımızın adaki matchini ararız. Kendinden büyük en küçük sayı yoksa en küçük sayı matchtir.<br>
9- B stackindeki sayıları sırayla matchlerinin üstüne göndeririz.<br>
