# Smart Vision Guard – Solusi Cegah Mata Rabun

## Deskripsi Proyek
Smart Vision Guard adalah proyek mikrokontroler berbasis **Arduino** yang dirancang sebagai **alat bantu menjaga kesehatan mata**.  
Alat ini berfungsi untuk mengingatkan pengguna agar menjaga **jarak pandang yang aman saat menggunakan laptop/TV** serta memastikan **pencahayaan ruangan cukup** dengan sistem lampu otomatis.

Proyek ini dibuat sebagai solusi sederhana untuk mencegah kebiasaan buruk seperti melihat layar terlalu dekat dan menggunakan gadget di ruangan gelap yang dapat menyebabkan mata cepat lelah dan rabun.

---

## Fungsi Utama Alat
1. **Menjaga Jarak Pandang Aman**
   - Mendeteksi jarak wajah ke layar menggunakan sensor ultrasonik
   - Jika jarak kurang dari 40 cm selama 10 detik:
     - Buzzer berbunyi
     - LED merah berkedip
     - LCD menampilkan peringatan bahaya
2. **Indikator Aman**
   - Jika jarak kembali aman (> 40 cm):
     - Alarm berhenti
     - LED hijau menyala sebagai indikator aman
3. **Lampu Otomatis**
   - Sensor LDR mendeteksi kondisi cahaya ruangan
   - Lampu otomatis menyala saat ruangan gelap
   - Lampu mati saat kondisi terang
4. **Tampilan Informasi**
   - LCD menampilkan status sistem
   - Menampilkan jarak objek
   - Menampilkan status lampu (ON/OFF)

---

## Komponen Elektronika
*(Arduino, resistor, jumper, dan breadboard tidak dihitung)*

- Sensor Ultrasonik HC-SR04  
- Sensor Cahaya (LDR)  
- LCD 16x2 I2C  
- Relay Module  
- Buzzer  
- LED Merah  
- LED Hijau  

Total: **7 komponen elektronika**

---

## Konfigurasi Pin
| Komponen | Pin Arduino |
|--------|-------------|
| Trigger Ultrasonik | D9 |
| Echo Ultrasonik | D10 |
| Buzzer | D8 |
| LED Merah | D6 |
| LED Hijau | D5 |
| Relay | D7 |
| LDR | A0 |

---

## Cara Kerja Sistem
1. Sensor ultrasonik membaca jarak antara pengguna dan layar.
2. Jika jarak kurang dari 40 cm, sistem mulai menghitung waktu selama 10 detik.
3. Jika pengguna tidak menjauh, alarm akan aktif.
4. Sensor LDR membaca intensitas cahaya ruangan.
5. Saat ruangan gelap, relay akan mengaktifkan lampu otomatis.
6. Semua status ditampilkan pada LCD dan Serial Monitor.

---

## Penerapan Alat
Smart Vision Guard dapat digunakan pada:
- Meja belajar
- Meja kerja
- Ruang belajar
- Rak TV

Alat ini membantu membentuk kebiasaan melihat layar dengan jarak dan pencahayaan yang sehat.

---

## Struktur File
