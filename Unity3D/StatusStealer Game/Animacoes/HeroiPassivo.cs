using UnityEngine;
using System.Collections;

public class HeroiPassivo : MonoBehaviour {

    //serve para "amortecer" a movimentação
    private float speed;
    //serve para definir a direção da rotacao atual
    float direcao;

    private float repeticao;//usado para limitar repeticao para apenas 1 loop
    private bool play;// serve como botão: true - liga , false - desliga
    private float controle;//serve como controle para esperar que se REaperte o play(o próximo true de : true-false-true)
   // public float limite;// LImite para repetição

    // Use this for initialization
    void Start () {

        //inicializando direção
        direcao = 1.0F;
        if (gameObject.CompareTag("Heroi"))
        {
            speed = 0.1F;
        }
        if (gameObject.CompareTag("Inimigo"))
        {
            speed = 0.08F;
        }

       // limite = 1.0F;
        repeticao =1.0F;
        controle = 0.0F;

    }
	
	// Update is called once per frame
	void Update () {

        if (controle == 0.0F)
        { // FORMULA GERAL
            if (play)// QUANDO APERTAR BOTÃO
            {

                repeticao = 0.0F; // VARIAVEL QUE QUERO    ALTERAR  
                controle++;
            }

        }

        if (controle >= 1.0F)//TUDO SÓ FUNCIONARA SE O BOTAO PLAY TIVER SIDO APERTADO
        {
            //posicao atual : y= -0.1213
            //verificar direcao e deninir sentido de direcao 
            if (direcao == 1.0F)//cima
        {
            //limite de rotacao e definicao de retorno
            if (transform.position.y >= -1.1F)//chegou no máximo - manda descer
            {
                transform.Translate(0,-speed*Time.deltaTime,0);
                
                direcao = -1.0F;
            }
            if (transform.position.y < -1.1F)//não chegou no máximo - manda subir
            {
                transform.Translate(0, speed * Time.deltaTime, 0);
               
            }
        }

        if (direcao == -1.0F)
        {

            if (transform.position.y > -1.1213F)//não chegou no mínimo - manda descer
            {
                transform.Translate(0, -speed * Time.deltaTime, 0);
               
            }
            if (transform.position.y <= -1.1213F && play )//chegou no mínimo e o botão PLAY esta ativo
            {
                transform.Translate(0, speed * Time.deltaTime, 0);
               
                direcao = 1.0F;
            }

            if (transform.position.y <= -1.1213F && !play)//chegou no mínimo e o botão PLAY esta desligado
                {
                transform.Translate(0, 0, 0);
                    repeticao ++;
                direcao = 1.0F;
            }
        }

        }

        if (!play && repeticao == 1.0F)// se botão play está desligado e chegou no fim da animação
        {
            controle = 0.0F;//forçando assim uma espera do botao play ser ativado
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


