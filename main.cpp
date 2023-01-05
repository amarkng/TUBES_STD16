
#include <string>
#include "lulus.h"

int main()
{
    //Parent
    listMhs LM;
    createListMhs(LM);
    infotypeMhs ifMhs;
    char nama[50];
    string nim,kelas;
    int nilai,poin;
    int i = 1;

    //Child
    listSts LS;
    createListSts(LS);
    infotypeSts ifSts;
    string lulus,bermasalah;
    int n = 1;
    //Tambahan
    int pilihan,jmlhMhs,jmlhSts;
    char backtomenu;

    pilihan = Menu();
    cout<<endl;
    while(pilihan != 0){
        switch(pilihan){
        case 1:{
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
            }break;
        case 2:{
            system("CLS");
            n = 1 ;
            string lulus2,bermasalah2;
            cout<<"Masukkan 4 Kategori Kelulusan : " <<endl;
            //cout<<"Berapa Kategori Kelulusan Yang Akan Anda Masukkan ? " ;
            //cin >> jmlhSts;
            while(n <= 4 ){
                cout << "> Kategori Kelulusan ke-"<<n<<endl;
                cout<<"Lulus/TidakLulus/t/t:";
                cin>>lulus2;
                cout<<"Bermasalah/TidakBermasalah/t:";
                cin>>bermasalah2;
                ifSts = newStatus(lulus2,bermasalah2);
                adrSts S = createElemenSts(ifSts);
                insertLastSts(LS,S);
                n++;
                cout<<endl;
            }
            }break;
        case 3:
            system("CLS");
            showAllMhs(LM);

            break;
        case 4:
            system("CLS");
            connecting(LM,LS);
            break;
        case 5:
            //menampilkan seluruh parent dan child yg sudah terkonek
            system("CLS");
            showAll(LM);
            break;
        case 6:{
            //cari data parent
            system("CLS");
            char nama6[50];
            cout<<"Nama Mahasiswa yang akan dicari : ";
            cin.ignore();
            cin.getline(nama6,50);
            adrMhs P = searchParent(LM, nama6);

            if(P!=NULL){
                cout<<"Berikut Data Mahasiswa Tersebut"<<endl;
                cout<<"Nama Mahasiswa : "<<infoMhs(P).namaMhs<<endl;
                cout<<"NIM Mahasiswa : "<<infoMhs(P).nimMhs<<endl;
                cout<<"Kelas Mahasiswa : "<<infoMhs(P).kelasMhs<<endl;
                cout<<"Nilai Mahasiswa : "<<infoMhs(P).nilai<<endl;
                cout<<"Poin Mahasiswa : "<<infoMhs(P).poin<<endl;
                if(child(P) != NULL){
                    adrSts Q = child(P);
                    cout<<"Status Kelulusan :" << infoSts(Q).lulus<< " dan " <<infoSts(Q).bermasalah<<endl;
                }else{
                    cout<<"Status Kelulusan : - " <<endl;
                }
            }else{
                cout<<endl;
                cout<<"Mahasiswa Tersebut Tidak Terdaftar";
            }
            }break;
        case 7:{
            //cari data child pada parent tertentu
            system("CLS");
            adrSts SS;
            char nama7 [50];

            cout<<"Masukkan Nama Mahasiswa : ";
            cin.ignore();
            cin.getline(nama7,50);
            SS = searchChildOnParent(LM,nama7);
            if(SS != NULL){
                cout<<"Status Kelulusan Mahasiswa "<<nama7<<" : ";
                cout << infoSts(SS).lulus << " dan "<<infoSts(SS).bermasalah<<endl;
            }else{
                cout<<"Belum Ada Status Kelulusan !" << endl;
            }
            }break;
        case 8:{
            //menghapus data parent dan childnya
            system("CLS");
            char nama8[50];
            adrMhs M;

            cout<<"Masukkan Nama Mahasiswa Yang Akan Dihapus Dari Data : ";
            cin.ignore();
            cin.getline(nama8,50);
            deleteDataMhs(LM,M,nama8);
            }break;
        case 9:{
            //menghapus data child pada parent tertentu
            system("CLS");
            string nama9;
            int nilai9;

            cout<<"Masukkan Nama Mahasiswa yang akan diperbarui nilainya : ";
            cin>>nama9;
            deleteChildonParent(LM,nama9);
            cout<<endl;
            if(searchParent(LM, nama9) != NULL){
                cout<<"Nilai terbaru : ";
                cin>>nilai9;
                updateNilai(LM, nama9, nilai9);
            }
            }break;
        case 10:{
            //jumlah child pada parent tertentu
            system("CLS");
            string lulus10,bermasalah10;

            cout<<"Masukkan Kategori Kelulusan nya  "<<endl;
            cout<<"Lulus/TidakLulus : ";
            cin>>lulus10;
            cout<<"Bermasalah/TidakBermasalah: ";
            cin>>bermasalah10;
            cout<<endl;
            if(counting(LM,LS,lulus10,bermasalah10) > 0){
                cout<<"Jumlah Mahasiswa Yang " << lulus10 << " dan " << bermasalah10 <<" : " << counting(LM,LS,lulus10,bermasalah10)<<" Mahasiswa"<<endl;
            }else{
                cout<<"Belum Ada Mahasiswa Yang Masuk Ke Kategori Tersebut!"<<endl;
            }
            //cout<<"Jumlah Mahasiswa Yang "<< lulus10 <<" dan "<< bermasalah10 <<counting(LM,LS,lulus10,bermasalah10)<<" Mahasiswa";
            }break;
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
