#include <stdlib.h>
#include "nbtrees.h"

int main() {
	isi_tree T1, T2;
	infotype cari;
	infotype parent, child;
	int pilihan, level;
	
	create_tree(T1);
	create_tree(T2);
	
	do {
		system("cls");
		printf("\n=== NON-BINARY TREE ===\n");
        printf("1. Buat Tree\n");
        printf("2. Traversal Tree (Pre, In, Post, Level Order)\n");
        printf("3. Print Tree (Struktur Hierarki)\n");
        printf("4. Search Node dalam Tree\n");
        printf("5. Jumlah Daun (Leaf)\n");
        printf("6. Cari Level Node\n");
        printf("7. Kedalaman (Depth) Tree\n");
        printf("8. Bandingkan Dua Tree\n");
        printf("9. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); 
        
        switch(pilihan) {
        	case 1:
        		printf("Membuat Tree default...\n");
                insert_some_node(T1);
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 2:
        		print_tree(T1);
        		printf("\nPre Order:\n");
                pre_order(T1);
                printf("In Order:\n");
                in_order(T1);
                printf("Post Order:\n");
                post_order(T1);
                printf("Level Order:\n");
                level_order(T1);
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 3:
        		printf("\nStruktur Tree:\n");
                print_tree(T1);
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 4:
        		printf("Masukkan node yang dicari: ");
                scanf(" %c", &cari);
                if (search(T1, cari)) {
                    printf("Node '%c' ditemukan dalam Tree.\n", cari);
                } else {
                    printf("Node '%c' TIDAK ditemukan.\n", cari);
                }
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 5:
        		printf("Jumlah Daun: %d\n", nb_Daun(T1));
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 6:
        		printf("Masukkan node yang ingin dicari level-nya: ");
                scanf(" %c", &cari);
                level = Level(T1, cari);
                if (level == -1)
                    printf("Node tidak ditemukan.\n");
                else
                    printf("Node '%c' berada pada level %d.\n", cari, level);
        		printf("Enter untuk melanjutkan..");
                getchar();
				break;
        	case 7:
        		printf("Kedalaman Tree (Depth): %d\n", Depth(T1));
        		printf("Enter untuk melanjutkan..");
                getchar();
        		break;
        	case 8:
        		printf("Membuat Tree Kedua...\n");
                insert_some_node(T2);
                if (nb_Elmt(T1) != nb_Elmt(T2)) {
                    printf("Tree tidak sama (jumlah node berbeda).\n");
                } else {
                    boolean sama = true;
                    for (int i = 1; i <= jml_maks; i++) {
                        if (T1[i].info != T2[i].info || T1[i].ps_fs != T2[i].ps_fs || T1[i].ps_nb != T2[i].ps_nb) {
                            sama = false;
                            break;
                        }
                    }
                    if (sama)
                        printf("Tree sama (struktur dan isi).\n");
                    else
                        printf("Tree TIDAK sama.\n");
                }
                printf("Enter untuk melanjutkan..");
                getchar();
        		break;
        	case 9:
        		printf("Terimakasih! Program selesai.. \n");
        		break;
        	default:
        		printf("Pilihan tidak valid!\n");
		}
	} while (pilihan != 9);
	
	return 0;
}
