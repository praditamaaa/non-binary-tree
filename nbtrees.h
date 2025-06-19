#ifndef NBTREES_H
#define NBTREES_H
#include <stdio.h>
#include <string.h>
#include "boolean.h"

// Maksimal node yang dapat ditampung dalam array
#define jml_maks 20

#define kebawah 1
#define keatas 2
#define kekanan 3
#define Nil 0

// =============================================
// ========= DEFINISI DTRUKTUR DATA ============
// =============================================

typedef char infotype;
typedef int address;
typedef struct nbtrees
{
    infotype info;
    address ps_fs;
    address ps_nb;
}nbtree;

typedef nbtree isi_tree[jml_maks+1];

// =============================================
// ============== MAIN FUNCTION ================
// =============================================

// IS:
// FS: 
// DESCRIPTION: 
void create_tree(isi_tree R);

// IS:
// FS: 
// DESCRIPTION: 
boolean is_empty_tree(isi_tree R);

// =============================================
// =========== TRANVERSAL FUNCTION =============
// =============================================

// IS:
// FS: 
// DESCRIPTION: 
void pre_order(isi_tree R);

void pre_order_recursive(isi_tree R, address P);

// IS:
// FS: 
// DESCRIPTION: 
void post_order(isi_tree R);

void post_order_recursive(isi_tree R, address P);

// IS:
// FS: 
// DESCRIPTION: 
void in_order(isi_tree R);

void in_order_recursive(isi_tree R, address P);

// IS:
// FS: 
// DESCRIPTION: 
void level_order(isi_tree R);

// =============================================
// =========== INSERTION FUNCTION ==============
// =============================================

address alloc_node(isi_tree R);
// IS:
// FS: 
// DESCRIPTION: 

// IS:
// FS: 
// DESCRIPTION: 
void insert_node(isi_tree R, infotype parent, infotype child);

// IS:
// FS: 
// DESCRIPTION: 
void insert_some_node(isi_tree R);

// =============================================
// ============ DELETION FUNCTION ==============
// =============================================

// IS:
// FS: 
// DESCRIPTION: 
void delete_node();

// IS:
// FS: 
// DESCRIPTION: 
void delete_level();


// =============================================
// =========== ADDITIONAL FUNCTION =============
// =============================================

// IS:
// FS: 
// DESCRIPTION: 
void print_tree(isi_tree R);

void print_tree_rec(isi_tree R, address root, char *prefix, boolean is_last);

// IS:
// FS: 
// DESCRIPTION: 
void print_tree_fa(isi_tree R);

// IS:
// FS: 
// DESCRIPTION: Mengirimkan true jika ada node dari P yang bernilai X
boolean search(isi_tree R, infotype x);

// IS:
// FS: 
// DESCRIPTION: Mengirimkan banyak elemen (node) di pohon non biner P
int nb_Elmt(isi_tree R);

// IS:
// FS: 
// DESCRIPTION:  Mengirimkan banyak daun (node) pohon non biner P
int nb_Daun (isi_tree R);

// IS:
// FS: 
// DESCRIPTION: Mengirimkan level dari node X yang merupakan salah satu simpul
int Level(isi_tree R, infotype X);

int Level_rec(isi_tree R, address P, infotype X, int level);

// IS:
// FS: 
// DESCRIPTION: Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon
int Depth(isi_tree R);

int Depth_rec(isi_tree R, address P);

// IS:
// FS: 
// DESCRIPTION: Mengirimkan Nilai terbesar dari dua data
int Max(int Data1, int Data2);

#endif // nbtrees.h
