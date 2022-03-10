using UnityEngine;
using System.Collections;

public class Chao : MonoBehaviour {

    private float velocidade;
    private Vector3 myPosition;
    private Vector3 positionNow;
    private float diferenca;
    private float diferenca1;
    private bool play;

    // Use this for initialization
    void Start () {
        //pega a posição inicial
        myPosition = transform.position;
        velocidade = 0.3F;
        //verifica qual tipo de objeto pela tag
        if (gameObject.CompareTag("Chao"))
        {
            velocidade = 0.3F;
        }
        if (gameObject.CompareTag("Montanha"))
        {
            velocidade = 0.05F;
        }
    }
	
	// Update is called once per frame
	void Update () {
       
        if(play){

            //movimentação
             transform.Translate(Time.deltaTime * (-velocidade), 0, 0);

            //pega a posição atual
             positionNow = transform.position;

            //calculo da diferença para comparação if 1.6 em x
            diferenca = myPosition.x - positionNow.x;
            diferenca1 = myPosition.x - positionNow.x;

             //quando é chao
            if (diferenca >= 1.195 && velocidade ==0.3F)
            {
                transform.position = myPosition;
            }
            //quando é Montanha
            if (diferenca1 >= 3 && velocidade == 0.1F)
            {
                transform.position = myPosition;
            }


            }
        
    }

    //FAÇO ESSES METHODOS POIS É NECESSÁRIO COMPARTILHAR VARIAVEIS COM SEGURANÇA
    public void SetPlay(bool roda){
        this.play = roda;
        
    }
    public bool GetPlay(){
        return play;
    }

}
