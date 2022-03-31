using UnityEngine;
using System.Collections;

public class Chao2 : MonoBehaviour {

	// Use this for initialization
	void Start () {//associa este objeto ao objeto em questao
	 transform.SetParent(GameObject.FindGameObjectWithTag("Chao").transform);
	}
	
	
}
