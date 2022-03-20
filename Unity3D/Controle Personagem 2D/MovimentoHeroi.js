#pragma strict
/*
	
	- movimento em relaçao ao tempo 
	- direcao da animacao pelas setas direcionais
	- velocidade de reproducao da animacao
*/


var rb2D: Rigidbody2D;


function Start() {
	rb2D = GetComponent.<Rigidbody2D>();
}


function FixedUpdate () {
    var vertical = Input.GetAxis("Vertical");
    var horizontal = Input.GetAxis("Horizontal");
    
 
 	
 	
 	
    if (vertical > 0 && horizontal == 0)
    {
    	//movimento em relaçao ao tempo
    	rb2D.MovePosition(rb2D.position + Vector2(0,0.8) * Time.fixedDeltaTime);
    	//direcao da animacao e velocidade de reproducao
    	GetComponent.<Animator>().SetInteger("Direction", 2);
    	GetComponent.<Animator>().speed = 1;
    }
    if (vertical < 0 && horizontal == 0)
    {
    	//movimento em relaçao ao tempo
   		rb2D.MovePosition(rb2D.position + Vector2(0,-0.8) * Time.fixedDeltaTime);
   		//direcao da animacao e velocidade de reproducao
        GetComponent.<Animator>().SetInteger("Direction", 0);
      	GetComponent.<Animator>().speed = 1;
      
    }
    if (horizontal > 0 && vertical == 0)
    {
    	//movimento em relaçao ao tempo
    	rb2D.MovePosition(rb2D.position + Vector2(0.8,0) * Time.fixedDeltaTime);
    	//direcao da animacao e velocidade de reproducao
    	GetComponent.<Animator>().SetInteger("Direction", 3);
       	GetComponent.<Animator>().speed = 1;
    }
    if (horizontal < 0 && vertical == 0)
    {
    	//movimento em relaçao ao tempo
    	rb2D.MovePosition(rb2D.position + Vector2(-0.8,0) * Time.fixedDeltaTime);
    	//direcao da animacao e velocidade de reproducao
    	GetComponent.<Animator>().SetInteger("Direction", 1);
       	GetComponent.<Animator>().speed = 1;
    }
    if(horizontal == 0 && vertical == 0){
    	//direcao da animacao e velocidade de reproducao
   		GetComponent.<Animator>().SetInteger("Direction", 4);
   	
    }
    
    
    
    
    
}

 