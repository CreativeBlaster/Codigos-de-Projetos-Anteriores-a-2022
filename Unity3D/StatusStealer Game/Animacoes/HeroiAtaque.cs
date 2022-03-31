using UnityEngine;
using System.Collections;

public class HeroiAtaque : MonoBehaviour {

    private GameObject heroi;

    private float smooth = 7.5F;//serve para "amortecer" a movimentação

    private float direcao;//serve para definir a direção da rotacao atual

   // private float repeticao;//usado para limitar repeticao para apenas 1 loop
    private bool play;// serve como botão: true - liga , false - desliga
    private float controle;//serve como controle para esperar que se REaperte o play(o próximo true de : true-false-true)
                           //public float limite;// LImite para repetição
    private bool fim;//NECESSÁRIO PARA CONTROLAR O DESLIGAMENTO DO PLAY

    private float movimentoMax;
    private Vector3 posInicial;
    private Vector3 positionNow;
    private float diferenca;
    private float velocidade;
    private bool rotina;
    private bool impacto;
    private Vector3 caminharFrente;
    private Vector3 caminharAtraz;

    

    // Use this for initialization
    void Start () {
        //limite = 1.0F;

        heroi = GameObject.FindWithTag("Heroi");

        direcao = 1.0F;
        //repeticao = 1.0F;
        controle = 0.0F;
        movimentoMax = 0.5F;
        posInicial.Set(-0.3161F,-1.1213F,0F);
        velocidade = 0.05F;
        rotina = false;
        impacto = false;
        fim = false;
        play = false;

        
    }
	
	// Update is called once per frame
	void Update () {

        if (gameObject.CompareTag("Heroi"))
        {
            diferenca = positionNow.x - posInicial.x;
            caminharAtraz = Vector3.left;
            caminharFrente = Vector3.right;
        }

        positionNow = transform.position;
        //calculo da diferença para comparação if 1.6 em x
        //diferenca = positionNow.x - posInicial.x  ;

        //IMPACTO - ao chegar na animação de espada À frente o impacto ocorre (linha 168)
        //NECESSÁRIO IMPLEMENTAR
        //if(impacto){

         //   impacto = false;
       // }

        // CONTROLE para fazer repetir apenas quando mandado
        if (controle == 0.0F)
        { // FORMULA GERAL
            if (play)// QUANDO APERTAR BOTÃO
            {
                rotina = true;
                //repeticao = 0.0F; // VARIAVEL QUE QUERO    ALTERAR  
                controle++;
            }

        }

        if (controle >= 1.0F)//TUDO SÓ FUNCIONARA SE O BOTAO PLAY TIVER SIDO APERTADO
        {

            //verificar direcao e deninir sentido de direcao 
            if (direcao == 1.0F)//anti-horário -direita
            {
                //limite de rotacao e definicao de retorno
                //if (!rotina && play) { //CONTINUA LOOP

                   // rotina = true;

               // }
                if (!rotina && fim) {

                    if (transform.rotation.z >= 0.0 )//rotação 0 manda volta
                    {

                        Quaternion target = Quaternion.Euler(0, 0, 0);
                        transform.rotation = target;


                        if (diferenca > 0.0F)//nao está na posicao original, manda voltar
                        {
                            transform.Translate(caminharAtraz * velocidade, Space.World);
                        }
                        if (diferenca <= 0.0F)//está na posicao original, manda parar
                        {
                            transform.Translate(0, 0, 0);
                            heroi.GetComponent<RESETPosicional>().SetPlay(true);
                            //repeticao++;
                            impacto = false;
                            play = false; // temina aqui ===assim espero


                        }


                    }
                    if (transform.rotation.z < 0.0  )//rotacao alterada
                    {



                        if (diferenca > 0.0F)//nao está na posicao original, manda voltar e rotacionar
                        {

                            Quaternion target = Quaternion.Euler(0, 0, 30);
                            transform.rotation = target;

                            transform.Translate(caminharAtraz * velocidade, Space.World);
                        }
                        if (diferenca <= 0.0F)//está na posicao original, manda apenas rotacionar
                        {

                            Quaternion target = Quaternion.Euler(0, 0, 30);
                            transform.rotation = target;

                            transform.Translate(0, 0, 0);
                        }

                    }

                }
                if (rotina) {

                    if (transform.rotation.z >= 0.29 )//chegou no maximo, muda sentido e manda pra baixo
                    {


                        if (diferenca >= movimentoMax)
                        {
                            Quaternion target = Quaternion.Euler(0, 0, -60);//x,y,z
                            
                            transform.rotation = Quaternion.Slerp(transform.rotation, target, 0.02352351F *smooth);
                            direcao = -1.0F;
                            transform.Translate(0, 0, 0);
                        }
                        if (diferenca < movimentoMax)
                        {
                            transform.Translate(caminharFrente* velocidade, Space.World);
                        }

                    }
                    if (transform.rotation.z < 0.29 )//não chegou no máximo(antihorário) manda chegar START
                    {

                        Quaternion target = Quaternion.Euler(0, 0, 60);//x,y,z
                        
                        transform.rotation = Quaternion.Slerp(transform.rotation, target,0.02352351F * smooth);


                        if (diferenca >= movimentoMax)
                        {
                            transform.Translate(0, 0, 0);
                        }
                        if (diferenca < movimentoMax)
                        {
                            transform.Translate(caminharFrente * velocidade, Space.World);
                        }


                    }
                }
                
            }

            if (direcao == -1.0F)//horário ,esquerda
            {

                if (transform.rotation.z > -0.29 )//se ->esquerda : e ele nao chegou no minimo, manda girar horario
                {

                    Quaternion target = Quaternion.Euler(0, 0, -60);//x,y,z
                    
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, 0.02352351F * smooth);
                }

                if (transform.rotation.z <= -0.29 )  //  PLay ativado - GIra SOBE
                {

                    Quaternion target = Quaternion.Euler(0, 0, 60);//x,y,z
                    
                    transform.rotation = Quaternion.Slerp(transform.rotation, target, 0.02352351F * smooth);
                    direcao = 1.0F;
                    
                    impacto = true;// IMPORTANTE NO CALCULO DE DANO
                    fim = true;
                    
                    rotina = false;

                }
                
            }

            if (!play )//&& repeticao
            {
                //*****chaga de bugssss RESETA TUTOOOO*****
                direcao = 1.0F;
                //repeticao = 1.0F;
                controle = 0.0F;
                movimentoMax = 0.5F;
                posInicial.Set(-0.3161F,-1.1213F,0F);
                velocidade = 0.05F;
                rotina = false;
                impacto = false;
                fim = false;
                play = false;

                
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

    public bool GetImpacto(){
        return impacto;
    }

}
