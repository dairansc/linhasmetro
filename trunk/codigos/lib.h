void erro(string mensagem, int tipo){
    cout << mensagem << endl;
    switch(tipo){
        case ERRO_CRITICO:
            cout << "Ocorreu um erro crítico, o programa será terminado" << endl;
            exit(-1);
        break;
    }
}
