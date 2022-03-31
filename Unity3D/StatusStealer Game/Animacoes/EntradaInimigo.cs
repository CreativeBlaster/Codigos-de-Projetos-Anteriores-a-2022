using UnityEngine;
using System.Collections;

public class EntradaInimigo : MonoBehaviour {

	private float velocidade;
    private Vector3 initialPosition;
    private Vector3 positionNow;

	private bool play;
	private bool chegou;

	// Use this for initialization
	void Start () {

	initialPosition.Set(1.338F,-1.119F,0F);
	velocidade = 0.3F;

	}
	
	// Update is called once per frame
	void Update () {
	
		if(play){

            
            //pega a posição atual
             positionNow = transform.position;

             
            if (positionNow.x <= 0.338F)//se já estiver na posicao
            {

                transform.Translate(0, 0, 0);//Para
				chegou = true;//CHEGOU
				play = false;
            
			}
			
            
            if (positionNow.x > 0.338F)//se nao estiver na posicao
            {
                transform.Translate(Time.deltaTime * (-velocidade), 0, 0);//movimentação
            }


            }
		

	}


	


	//FAÇO ESSES METHODOS POIS É NECESSÁRIO COMPARTILHAR VARIAVEIS COM SEGURANÇA
    public void SetPlay(bool roda){
        this.play = roda;
        
    }
    public bool GetPlay(){
        return this.play;
    }

	public void SetChegou(bool chega){
        this.chegou = chega;
        
    }
	public bool GetChegou(){
        return this.chegou;
    }


}
