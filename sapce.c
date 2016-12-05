#include <stdio.h>
#include <stdlib.h>
void cargar(int m[15][15]);
void imprimir(int m[15][15]);
void pjugador(int m[15][15],int pi[4],int pj[4]);
void desapjuga(int m[15][15],int pi[4],int pj[4]);
struct disparo{
	int pi,pj,act;
};

struct jugador{
	int pi[4],pj[4];
	int vida,puntaje;
	struct disparo dis;
};
struct enemigo{
	int pi,pj;
	int vivo;
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int m[15][15];
	cargar(m);
	
	imprimir(m);
	jugar(m);
	return 0;
}
void cargar(int m[15][15]){
	int i,j;
	
	for(i=0;i<15;i++){
		
		for(j=0;j<15;j++){
			if(i==0||j==0||i==14||j==14){
				m[i][j]=219;
			}
			else{
				m[i][j]=32;
			}
		}
	}
}
void imprimir(int m[15][15]){
	int i,j;
	for(i=0;i<15;i++){
		printf("\n");
		for(j=0;j<15;j++){
			printf("%c",m[i][j]);
		}
	}
}
void jugar(int m[15][15]){
	struct jugador nave;
	struct enemigo ene[13];
	int i,j;
	char tecla=0;
	int cont;
	nave.vida=3;
	nave.puntaje=0;
	nave.dis.act=0;
	nave.pj[0]=6;
	nave.pi[0]=13;
	nave.pj[1]=5;
	nave.pi[1]=13;
	nave.pj[2]=7;
	nave.pi[2]=13;
	nave.pj[3]=6;
	nave.pi[3]=12;
	pjugador(m,nave.pi,nave.pj);
	for(i=0;i<13;i++){
		ene[i].vivo=0;
	}
	while(tecla!='X'){
		if(kbhit()){
		tecla=getch();
		tecla=toupper(tecla);
	}
	desapjuga(m,nave.pi,nave.pj);
	if(tecla=='A'){
		if(m[nave.pi[1]][nave.pj[1]-1]!=219){
			for(i=0;i<4;i++){
				nave.pj[i]--;
			}
		}
	}
	if(tecla=='D'){
		if(m[nave.pi[2]][nave.pj[2]+1]!=219){
			for(i=0;i<4;i++){
				nave.pj[i]++;
			}
		}
	}
	pjugador(m,nave.pi,nave.pj);
	if(tecla==32){
		if(nave.dis.act==0){
			nave.dis.act=1;
			nave.dis.pi=nave.pi[3]+1;
			nave.dis.pj=nave.pj[3];
		}
	}
	int band=0;
	for(i=0;i<13;i++){
		if(ene[i].vivo==1){
			band=1;
		}
	}
	if(band==0){
		for(i=0;i<13;i++){
			ene[i].pi=1;
			ene[i].pj=i+1;
			ene[i].vivo=1;
		}
	}
	
	if(nave.dis.act==1){
		m[nave.dis.pi][nave.dis.pj]=32;
		if(m[nave.dis.pi-1][nave.dis.pj]!=219){
			nave.dis.pi--;
		}else{
			nave.dis.act=0;
		}
		if(nave.dis.act==1){
			m[nave.dis.pi][nave.dis.pj]=34;
		}
	}
	if(cont==3){
		cont=0;
	for(i=0;i<13;i++){
		if(ene[i].vivo==1){
			m[ene[i].pi][ene[i].pj]=32;
			if(m[ene[i].pi+1][ene[i].pj]!=219){
				ene[i].pi++;
				m[ene[i].pi][ene[i].pj]=31;
			}else{
				ene[i].vivo=0;
			}
		}
	}
}
    for(i=0;i<13;i++){
    	if(ene[i].vivo==1){
    		if(nave.dis.act==1){
			
    		if(ene[i].pi==nave.dis.pi&&ene[i].pj==nave.dis.pj){
    			ene[i].vivo=0;
    			nave.dis.act=0;
    			nave.puntaje++;
    			m[ene[i].pi][ene[i].pj]=32;
			}
		}
			for(j=0;j<4;j++){
				if(ene[i].pi==nave.pi[i]&&ene[i].pj==nave.pj[i]){
					ene[i].vivo=0;
					nave.vida--;
				}
			}
		}
	}
	if(nave.vida<=0){
		printf("Perdio");
		return;
	}
	cont++;	
	tecla=0;
	system("CLS");
	
	imprimir(m);
	printf("\n\n\t\tVidas de juego: %d\n",nave.vida);
	Sleep(100);
	}
}
void pjugador(int m[15][15],int pi[4],int pj[4]){
	m[pi[0]][pj[0]]=254;
	m[pi[1]][pj[1]]=254;
	m[pi[2]][pj[2]]=254;
	m[pi[3]][pj[3]]=30;
	
}
void desapjuga(int m[15][15],int pi[4],int pj[4]){
	int k;
	for(k=0;k<4;k++){
		m[pi[k]][pj[k]]=32;
	}
}
