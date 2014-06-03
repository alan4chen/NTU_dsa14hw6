#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
extern "C"{
#include "avl_ntudsa.h"
}

using namespace std;

struct data{
	int score[6];
	string student_id;
};

void get_rank_id(const struct avl_node *node, int rank){
	if (rank == node->avl_cnode[0] + 1){
		cout << ((struct data *)node->avl_data)->student_id << "\n";
		return;
	}
	else if (rank <= node->avl_cnode[0]){
		get_rank_id(node->avl_link[0], rank);
	}
	else{
		get_rank_id(node->avl_link[1], rank - node->avl_cnode[0] - 1);
	}
}

int int_compare(const void *pa, const void *pb, void *param){
	const struct data * a = (const struct data *)pa;
	const struct data * b = (const struct data *)pb;
	if (a->score[0] > b->score[0]) return -1;
	else if (a->score[0] < b->score[0]) return 1;
	else{
		if (a->score[2] > b->score[2]) return -1;
		else if (a->score[2] < b->score[2]) return 1;
		else{
			if (a->score[3] > b->score[3]) return -1;
			else if (a->score[3] < b->score[3]) return 1;
			else{
				if (a->score[5] > b->score[5]) return -1;
				else if (a->score[5] < b->score[5]) return 1;
				else{
					if (a->score[4] > b->score[4]) return -1;
					else if (a->score[4] < b->score[4]) return 1;
					else{
						if (a->score[1] > b->score[1]) return -1;
						else if (a->score[1] < b->score[1]) return 1;
						else return a->student_id.compare(b->student_id);
					}
				}
			}
		}
	}
}


void get_ave(int *score){
	int sum = 0;
	for (int i = 1; i <= 5; i++){
		sum += score[i];
	}
	score[0] = sum / 5;
}

int main(){
	struct avl_table *tree_avl;
	tree_avl = avl_create(int_compare, NULL, NULL);

	string str;
	while (cin >> str){
		if (str[0] == 'p'){
			struct data *d = new struct data;
			cin >> d->student_id >> d->score[1] >> d->score[2] >> d->score[3] >> d->score[4]
				>> d->score[5];
			 get_ave(d->score);
		//	 cout << "----" << d->student_id << " " << d->score[0] << " " << d->score[1] << "\n";
			 void **p1 = avl_probe(tree_avl, d);
		}
		else{
			int rank; cin >> rank;
			if (rank > tree_avl->avl_root->avl_cnode[0] + tree_avl->avl_root->avl_cnode[1] + 1)
				cout << "not found\n";
			get_rank_id(tree_avl->avl_root, rank);
		}
	}
}


