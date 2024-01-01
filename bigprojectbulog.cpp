#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main()
{
    string nama_barang[100], tempat_nama, dicari;
    float harga_barang[100], tempat_harga, total_harga;
    int stok_barang[100], tempat_stok, i, cek, jumlah_barang, total_barang, total_stok;
    cout<<"\t\t\tKelompok 4 Teknologi Informasi A"<<endl;
    cout<<"Akmal Maulana    ||  Puji Pangestu   ||  Della Eggy Puspita Dewi ||  Revina Dyan Salma"<<endl;
    cout<<endl;

    cout<<"===========================PROGRAM PERGUDANGAN BULOG==========================="<<endl<<endl<<endl;
    cout<<endl;//fungsi menampilkan cout endl utk memberi baris kosong
    cout<<"Tentukan Berapa Barang yang Ingin Ditentukan:    ";
    cin>>jumlah_barang;
    cout<<endl;

    //penginputan data menggunakan looping dan array
    for(i=0; i<jumlah_barang; i++)//agar tabel rapi usahakan inputan tidak lebih dari 6 karakter
    {
       cout<<"=====================\tKeranjang "<<i+1<<" ====================="<<endl<<endl;
       cout<<"Masukkan Nama Barang  :   ";
       cin>>nama_barang[i];
       cout<<"Masukkan Harga Barang :   ";
       cin>>harga_barang[i];
       cout<<"Masukkan Stok Barang  :   ";
       cin>>stok_barang[i];
       cout<<endl;
    }
    system("cls");


    //menghitung jumlah total barang, harga, dan stok menggunakan Loopingg
    total_barang=jumlah_barang;//disini nilai total barang itu sama dengan jumlah barang
    for(int g=0; g<jumlah_barang; g++)//jadi perulangan akan dilakukan apabila g kurang dari jumlah barang
    {
        total_harga=total_harga+harga_barang[g];//disini terdapat aritmatika penjumlahan
    }
    for(int g=0; g<jumlah_barang; g++)
    {
        total_stok=total_stok+stok_barang[g];
    }


    system("cls");
    int pilih;
    cout<<"=================================MENU PROGRAM================================="<<endl;
    cout<<"1. Cari Barang"<<endl;
    cout<<"2. Lihat Semua Barang"<<endl;
    cout<<"9. Keluar"<<endl;
    cout<<"Masukkan Pilihan (1/2): ";
    cin>>pilih;
    switch(pilih)
    {
        case 1:
            system("cls");
            cout<<"==============================CEK STOK BARANG==========================="<<endl;
            cek=0;
            cout<<"Masukkan nama barang yang dicari : ";
            cin>>dicari;
            //proses pencarian menggunakan sekuensial search/pencarian beruntun
            for(i=0; i<jumlah_barang; i++)
            {
                if(nama_barang[i]==dicari)
                {
                    cek = 1;
                    break;
                }
            }
            if(cek==1)
            {
                cout<<"Data ditemukan di bagian ke "<<i+1<<endl;
                cout<<"Nama Barang  : "<<nama_barang[i]<<endl;
                cout<<"Harga Barang : "<<harga_barang[i]<<endl;
                cout<<"Jumlah Stok  : "<<stok_barang[i]<<endl;
            }
            else
                cout<<"BARANG TIDAK DITEMUKAN!"<<endl;
        break;
        case 2:
            int pilih2;
            system ("cls");
            cout<<"=================================LIHAT SEMUA BARANG================================"<<endl;
            cout<<"1. Lihat Berdasarkan Nama Barang"<<endl;
            cout<<"2. Lihat Barang Berdasarkan Harga"<<endl;
            cout<<"3. Lihat Barang Berdasarkan Jumlah Stok"<<endl;
            cout<<"9. Kembali"<<endl;
            cout<<"Masukkan Pilihan (1-3): ";
            cin>>pilih2;
            switch(pilih2)//switch case merupakan percabangan, switch pilih2 artinya untuk pilihan kedua
            {
                case 1:
                    //menampilkan data berdasarkan nama barang +1
                    system("cls");
                    cout<<"\t\t\t LIST BERDASARKAN NAMA BARANG"<<endl;
                    cout<<endl;//jadi cout endl utk nampilin baris kosong
                    cout<<"|========================================================================================================|"<<endl;
                    cout<<"| NO. |      Nama Barang       |              Harga Barang      |            Jumlah Stok                 |"<<endl;
                    cout<<"|========================================================================================================|"<<endl;
                    for(i=0; i<jumlah_barang; i++)
                    {
                        cout<<"| "<<i+1<<"   |\t        "<<nama_barang[i]<<"\t       |\t\t"<<harga_barang[i]<<"\t        |\t\t "<<stok_barang[i]<<"\t\t\t |"<<endl;
                    }
                    cout<<"|========================================================================================================|"<<endl;
                    cout<<"|TOTAL|\t        "<<total_barang<<"\t       |\t\t"<<total_harga<<"\t        |\t\t "<<total_stok<<"\t         |"<<endl;
                    cout<<"|========================================================================================================|"<<endl;
                break;
                case 2:
                    //proses sorting berdasarkan harga menggunakan bubble short
                    for(int x=0; x<jumlah_barang; x++)
                    {
                        for(int y=0; y<jumlah_barang; y++)
                        {
                            if(harga_barang[x]<harga_barang[y])
                            {
                                //tukar harga barang
                                tempat_harga=harga_barang[x];
                                harga_barang[x]=harga_barang[y];
                                harga_barang[y]=tempat_harga;

                                //tukar nama barang
                                tempat_nama=nama_barang[x];
                                nama_barang[x]=nama_barang[y];
                                nama_barang[y]=tempat_nama;

                                //tukar jumlah stok
                                tempat_stok=stok_barang[x];
                                stok_barang[x]=stok_barang[y];
                                stok_barang[y]=tempat_stok;
                            }
                        }
                    }
                    //menampilkan data yang telah diurut berdasarkan harga ascending
                    system("cls");
                    cout<<"\t\t\t LIST BARANG BERDASARKAN HARGA"<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                    cout<<"| NO. |      Nama Barang       |             Harga Barang       |             Jumlah Stok                 |"<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                    for(i=0; i<jumlah_barang; i++)
                    {
                        cout<<"| "<<i+1<<"   |\t        "<<nama_barang[i]<<"\t       |\t\t"<<harga_barang[i]<<"\t        |\t\t "<<stok_barang[i]<<"\t\t\t  |"<<endl;
                    }
                    cout<<"|=========================================================================================================|"<<endl;
                    cout<<"|TOTAL|\t        "<<total_barang<<"\t       |\t\t"<<total_harga<<"\t        |\t\t "<<total_stok<<"\t          |"<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                break;
                case 3:
                    //proses sorting berdasarkan jumlah stok menggunakan bubble sort
                    for(int x=0; x<jumlah_barang; x++)
                    {
                        for(int y=0; y<jumlah_barang; y++)
                        {
                            if(harga_barang[x]<harga_barang[y])
                            {
                                //tukar harga barang
                                tempat_harga=harga_barang[x];
                                harga_barang[x]=harga_barang[y];
                                harga_barang[y]=tempat_harga;

                                //tukar nama barang
                                tempat_nama=nama_barang[x];
                                nama_barang[x]=nama_barang[y];
                                nama_barang[y]=tempat_nama;

                                //tukar jumlah stok
                                tempat_stok=stok_barang[x];
                                stok_barang[x]=stok_barang[y];
                                stok_barang[y]=tempat_stok;
                            }
                        }
                    }
                    //menapilkan data yang telah diurut berdasarkan stok ascending
                    system("cls");
                    cout<<"\t\t\t LIST BARANG BERDASARKAN JUMLAH STOK "<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                    cout<<"| NO. |      Nama Barang       |             Harga Barang       |               Jumlah Stok               |"<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                    for(i=0; i<jumlah_barang; i++)
                    {
                        cout<<"| "<<i+1<<"   |\t        "<<nama_barang[i]<<"\t       |\t\t"<<harga_barang[i]<<"\t        |\t\t "<<stok_barang[i]<<"\t\t\t  |"<<endl;
                    }
                    cout<<"|=========================================================================================================|"<<endl;
                    cout<<"|TOTAL|\t        "<<total_barang<<"\t       |\t\t"<<total_harga<<"\t        |\t\t "<<total_stok<<"\t          |"<<endl;
                    cout<<"|=========================================================================================================|"<<endl;
                break;
                }
    }
    return 0;

}
