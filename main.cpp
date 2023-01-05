
#include <string>
#include "lulus.h"


int main()
{
    listMhs LM;
    createListMhs(LM);
    infotypeMhs ifMhs;
    char nama[50];
    string nim,kelas;
    int nilai,poin;
    int i = 1;
    //
    listSts LS;
    createListSts(LS);
    infotypeSts ifSts;
    string lulus,bermasalah;
    int n = 1;
    //
    int pilihan,jmlhMhs,jmlhSts;
    char backtomenu;

    pilihan = Menu();
    cout<<endl;
    while(pilihan != 0){
        switch(pilihan){
        case 1:
            system("CLS");
            cout<<"Berapa Data Mahasiswa Yang Akan Anda Masukkan ? " ;
            cin >> jmlhMhs;
            while(i <= jmlhMhs ){
                cout << "> Mahasiswa ke-"<<i<<endl;
                cout<<"Nama Mahasiswa : "; //ngetes doang
                cin.ignore();
                cin.getline(nama,50);
                cout<<"Nim Mahasiswa : ";
                cin>> nim;
                cout<<"Kelas Mahasiswa : ";
                cin >> kelas;
                cout<<"Nilai Mata Kuliah : ";
                cin>> nilai;
                cout<<"Poin Pelanggaran : ";
                cin >> poin;
                ifMhs = newMahasiswa(nama,nim,kelas,nilai,poin);
                adrMhs M = createElemenMhs(ifMhs);
                insertFirstMhs(LM,M);
                i++;
                cout<<endl;
            }
            break;
        case 2:
            system("CLS");
            cout<<"Berapa Kategori Kelulusan Yang Akan Anda Masukkan ? " ;
            n = 1 ;
            cin >> jmlhSts;
            while(n <= jmlhSts ){
                cout << "> Kategori Kelulusan ke-"<<n<<endl;
                cout<<"Lulus/Tidak Lulus : ";
                cin>>lulus;
                cout<<"Bermasalah/Tidak Bermasalah : ";
                cin>>bermasalah;
                ifSts = newStatus(lulus,bermasalah);
                adrSts S = createElemenSts(ifSts);
                insertLastSts(LS,S);
                n++;
                cout<<endl;
            }
            break;
        case 3:
            system("CLS");
            showAllMhs(LM);

            break;
        case 4:
            system("CLS") ;
            connecting(LM,LS);
            cout<<"Proses Berhasil Dilakukan ! ";
            break;
        case 5:
            //menampilkan seluruh parent dan child yg sudah terkonek
            showAll(LM);
            break;
        case 6:{
            //cari data parent
            char mhsss[50];
            cout<<"Nama Mahasiswa yang akan dicari : ";
            cin.getline(mhsss,50);
            adrMhs P = searchParent(LM, mhsss);

            if(P!=NULL){
                cout<<"Berikut Data Mahasiswa : "<<endl;
                cout<<"Nama Mahasiswa : "<<infoMhs(P).namaMhs<<endl;
                cout<<"NIM Mahasiswa : "<<infoMhs(P).nimMhs<<endl;
                cout<<"Kelas Mahasiswa : "<<infoMhs(P).kelasMhs<<endl;
                cout<<"Nilai Mahasiswa : "<<infoMhs(P).nilai<<endl;
                cout<<"Poin Mahasiswa : "<<infoMhs(P).poin<<endl;
            }else{
                cout<<endl;
                cout<<"Mahasiswa Tersebut Tidak Terdaftar";

            }
            }break;
        case 7:{
            //cari data child pada parent tertentu
            showchild(LS);
            cout<<"sc";
            }break;
        case 8:
            //menghapus data parent dan childnya
            cout<<"";
            break;
        case 9:
            //menghapus data child pada parent tertentu
            cout<<"";
            break;
        case 10:
            //jumlah child pada parent tertentu
            cout<<"";
            break;
        }
        cout<<endl;
        cout<<"Kembali Ke Menu Utama ? (Y/N) : ";
        cin >> backtomenu;
        system("CLS");
        if(backtomenu == 'Y' || backtomenu == 'y'){
            pilihan = Menu();
        }else{
            pilihan = 0;
        }
        cout<<endl;
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM"<<endl;

    return 0;
}
