# incluye  < iostream >
# include  " snake.h "
# incluye  " startShip.h "

usando el  espacio de nombres  std ;

 menú vacío ()
{
   int opcion = 0 ;

    mientras ( cierto )
    {
        sistema ( " cls " );
        
        cout << " ****** " ;
        cout << " MENÚ DEL JUEGO " ;
        cout << " ****** " ;
        cout << endl;
        cout << " 1 - Serpiente " << endl;
        cout << " 2 - Nave espacial " << endl;
        cout << " 0 - Salir " << endl;
        cout << endl;
        cout << " Ingrese una opcion: " ;
        cin >> opcion;

        si (opcion == 0 )
        {
            romper ;
        }
        si (opcion == 1 )
        {
            sistema ( " cls " );
            serpiente ();
            sistema ( " pausa " );
        }
        si (opcion == 2 )
        {
            sistema ( " cls " );
            starShip ();
            sistema ( " pausa " );
        }
        si (opcion < 0 || opcion> 2 )
        {
            sistema ( " cls " );
            cout << " Debe ingresar una opcion entre 0, 1 y 2 " << endl;
            romper ;
        }
    }
}