#include "nbtrees.h"

void create_tree(isi_tree R) {
	int i;
	for (i = 1; i <= jml_maks; i++) {
		R[i].info = '\0';
		R[i].ps_fs = Nil;
		R[i].ps_nb = Nil;
	}
}

boolean is_empty_tree(isi_tree R) {
	return R[1].info == '\0';
}

void pre_order(isi_tree R) {
	if(!is_empty_tree(R)) {
		pre_order_recursive(R, 1);
		printf("\n");
	}
}

void pre_order_recursive(isi_tree R, address P) {
	if(P != Nil) {
		printf("%c ", R[P].info);
		pre_order_recursive(R, R[P].ps_fs);
		pre_order_recursive(R, R[P].ps_nb);
	}
}

void post_order(isi_tree R) {
	if(!is_empty_tree(R)) {
		post_order_recursive(R, 1);
		printf("\n");
	}	
}

void post_order_recursive(isi_tree R, address P) {
	if(P != Nil) {
		post_order_recursive(R, R[P].ps_fs);
		post_order_recursive(R, R[P].ps_nb);
		printf("%c ", R[P].info);
	}
}

void in_order(isi_tree R) {
	if(!is_empty_tree(R)) {
		in_order_recursive(R, 1);
		printf("\n");
	}
}

void in_order_recursive(isi_tree R, address P) {
	if(P != Nil) {
		in_order_recursive(R, R[P].ps_fs);
		printf("%c ", R[P].info);
		in_order_recursive(R, R[P].ps_nb);
	}
}

void level_order(isi_tree R) {
	if(is_empty_tree(R)) return;
	address queue[jml_maks];
	int front = 0;
	int rear = 0;
	queue[rear++] = 1;
	
	while(front < rear) {
		address P = queue[front++];
		printf("%c ", R[P].info);
		address child = R[P].ps_fs;
		while(child != Nil) {
			queue[rear++] = child;
			child = R[child].ps_nb;
		}
	}
	printf("\n");
}

address alloc_node(isi_tree R) {
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info == '\0') return i;
	}
	return Nil;
}

void insert_node(isi_tree R, infotype parent, infotype child) {
	if(is_empty_tree(R)) {
		int root = alloc_node(R);
		if(root != Nil) {
			R[root].info = child;
		}
		return;
	}
	
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info == parent) {
			int new_node = alloc_node(R);
			if(new_node == Nil) return;
			R[new_node].info = child;
			
			if (R[i].ps_fs == Nil) {
				R[i].ps_fs = new_node;
			} else {
				address temp = R[i].ps_fs;
				while (R[temp].ps_nb != Nil) temp = R[temp].ps_nb;
				R[temp].ps_nb = new_node;
			}
			return;
		}
	}
}

void insert_some_node(isi_tree R) {
	insert_node(R, '\0', 'A');
    insert_node(R, 'A', 'B');
    insert_node(R, 'A', 'C');
    insert_node(R, 'B', 'D');
    insert_node(R, 'B', 'E');
    insert_node(R, 'C', 'F');
}

void delete_node() {
	//NOT DONE
}

void delete_level() {
	//NOT DONE
}

void print_tree(isi_tree R) {
	if (!is_empty_tree(R)) {
        print_tree_rec(R, 1, "", true); 
    }
}

void print_tree_rec(isi_tree R, address node, char *prefix, boolean is_last) {
    if (node == Nil) return;

    printf("%s", prefix);

    if (is_last) {
        printf("+-- ");
    } else {
        printf("+-- ");
    }

    printf("%c\n", R[node].info);

    char new_prefix[100];
    strcpy(new_prefix, prefix);
    strcat(new_prefix, is_last ? "    " : "¦   ");

    int child_count = 0;
    address temp = R[node].ps_fs;
    while (temp != Nil) {
        child_count++;
        temp = R[temp].ps_nb;
    }

    int i = 0;
    address child = R[node].ps_fs;
    while (child != Nil) {
        print_tree_rec(R, child, new_prefix, i == child_count - 1);
        i++;
        child = R[child].ps_nb;
    }
}


void print_tree_fa(isi_tree R) {
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info != '\0') {
			printf("Node %c: ", R[i].info);
			if(R[i].ps_fs != Nil) {
				printf("First chils = %c, ", R[R[i].ps_fs].info);
			}
			if(R[i].ps_nb != Nil) {
				printf("Next siblings = %c, ", R[R[i].ps_nb].info);
			}
			printf("\n");
		}
	}
}

boolean search(isi_tree R, infotype x) {
	int i;
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info == x) return true;
	}
	return false;
}

int nb_Elmt(isi_tree R) {
	int i;
	int count = 0;
	
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info != '\0') count++;
	}
	return count;
}

int nb_Daun(isi_tree R) {
	int i;
	int count = 0;
	
	for (i = 1; i <= jml_maks; i++) {
		if(R[i].info != '\0' && R[i].ps_fs == Nil) count++;
	}
	return count;
}

int Level(isi_tree R, infotype X) {
	return Level_rec(R, 1, X, 1);
}

int Level_rec(isi_tree R, address P, infotype X, int level) {
	if(P == Nil) return -1;
	if(R[P].info == X) return level;
	
	int res = Level_rec(R, R[P].ps_fs, X, level + 1);
	if (res != -1) return res;
	
	return Level_rec(R, R[P].ps_nb, X, level);
}

int Depth(isi_tree R) {
	return Depth_rec(R, 1);
}

int Depth_rec(isi_tree R, address P) {
	if(P == Nil) return 0;
	
	int child_depth = Depth_rec(R, R[P].ps_fs);
	int sibling_depth = Depth_rec(R, R[P].ps_nb);
	
	return Max(child_depth + 1, sibling_depth);
}

int Max(int Data1, int Data2) {
	return (Data1 > Data2) ? Data1 : Data2;
}
