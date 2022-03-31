using UnityEngine;
using System.Collections;

public class HeroiAndando : MonoBehaviour {

    //serve para "amortecer" a movimentação
    private float smooth = 4.0F;
    //serve para definir a direção da rotacao atual
    private float direcao;

    private float repeticao;//usado para limitar repeticao para apenas 1 loop
    private bool play;// serve como botão: true - liga , false - desliga
    private float controle;//serve como controle para esperar que se REaperte o play(o próximo true de : true-false-true)
   // public float limite;// LImite para repetição

    // Use this for initialization
    void Start () {

        //inicializando
        direcao = 1.0F;
        //limite = 5.0F;
        repeticao = 1.0F;
        controle = 0.0F;
    }
	
	// Update is called once per frame
	void Update () {

        // CONTROLE para fazer repetir apenas quando mandado
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

            //verificar direcao e deninir sentido de direcao 
            if (direcao == 1.0F)
            {
                //limite de rotacao e definicao de retorno
                if (transform.rotation.z >= 0.20 && play)//chegou no máximo - manda descer
                {

                    Quaternion target = Quaternion.Euler(0, 0, -30);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                    direcao = -1.0F;
                    
                }
                if (transform.rotation.z < 0.20 && play)//começa aqui
                {

                    Quaternion target = Quaternion.Euler(0, 0, 30);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                    
                }

                if (transform.rotation.z < 0.0 && !play)//chegou no limite mas nao está na origem - manda girar
                {
                    
                    Quaternion target = Quaternion.Euler(0, 0, 30);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);

                }

                if (transform.rotation.z >= 0.0 && !play)//chegou no limite, está na origem - manda parar
                {

                    Quaternion target = Quaternion.Euler(0, 0, 0);
                    transform.rotation = target;
                    repeticao ++;

                }
            }

            if (direcao == -1.0F)
            {

                if (transform.rotation.z > -0.20)
                {

                    Quaternion target = Quaternion.Euler(0, 0, -30);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                }
                if (transform.rotation.z <= -0.20)
                {

                    Quaternion target = Quaternion.Euler(0, 0, 30);//x,y,z
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, Time.deltaTime * smooth);
                    direcao = 1.0F;
                }

            }

            if (!play && repeticao == 1.0F )
            {
                controle = 0.0F;
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
