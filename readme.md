# Data Structure 

## Assignment
    Antrian pada sistem pembelian tiket bioskop menangani pembayaran dan pengembalian sisa uang tiket dengan pecahannya  dan penjadwalan film yang tanyang (jumlah room bioskop ada 3) dengan kapasitas kursi terbatas setiap room.
### Breakdowns
- Antrian (queue)
- pembayaran (payment/cashier system using stack for arithmetics)
- penjadwalan film (graph, searching, sorting, hashing)
## Things Needed
### Required
- Array Application
- ADT 
- Stack and Queue
- Sorting and Searching Algorithm Implementation
### Selective
- Graph Integration
### Optional
- Linked List Integration
- Recursion Implementation
- Hashing implementation

# Concepts

## Queue System
1. Ketika pelanggan mengantri, maka queue akan ditambahkan data pengguna (basic info)
2. ketika keluar dari antrian (sudah paling depan), menanggil fungsi untuk pembayaran

## Cashier System
1. Ketika pelanggan hendak memilih film yang akan ditonton, akan ada pencarian film dalam jadwal yang ditentukan
2. Periksa keadaan film dalam jadwal
    - Bila ada pada jadwal:
        - Lakukan Prosedur pembayaran
    - Bila tidak DAN keluar, --> EXIT
4. PEMBAYARAN
    - terima uang dari pelanggan
        - Bila uang pas, --> 5
        - Bila tidak, lakukan perhitungan differensial uang dengan biaya
            - Bila kurang, --> ERROR
            - Bila lebih, --> 5
5. KONFIRMASI
    - Bila uang pas, maka konfirmasi tidak ada nominal sisa
    - Bila uang lebih, maka konfirmasi nominal sisa dalam pecahan paling optimal
6. ERROR
    - Bila ERROR karena tidak ada tempat pada film yang dicari, maka
        - Sarankan film lainnya
            - Bila disetujui, --> 2
            - Bila tidak, --> EXIT

## Film Scheduling
1. Periksa apakah film yang dimaksud berada dalam jadwal sekarang
2. Bila ada pada jadwal:
    - Periksa keadaan kapasitas
        - Bila masi ada ruang, maka lakukan hashing untuk menghindari pelanggan yang sama
        - Bila tidak ada ruang, --> 4
3. Bila tidak ada pada jadwal, --> 4
4. ERROR
    - Bila ERROR karena tidak ada tempat pada film yang dicari, maka
        - Sarankan film lainnya
            - Bila disetujui, --> 2
            - Bila tidak, --> EXIT

# Modules
## Cashier
- Reverse Polish Notation (Stack, Linked List, ADT)

## Film Scheduler 
- Graph (Coloring, ADT)
- Hash Table (Sorting, Searching, Linked List, ADT, Recursion, Hashing)

## Queue System (in main app)
- Queue (Queue, ADT, Linked List)