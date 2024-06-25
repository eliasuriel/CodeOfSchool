"""

Este programa ayudara a los alumnos a mejorar en la prueba tipo pisa

"""
import random
lista=["Lectura","Matemáticas"]
def lectura(opc):
    respuestas_correctas=[]
    respuesta=[]
    lista_nombre=[]
    lista_correctas=[]
    datos=["e","c","d","a","c"]
    if opcion==1:
        print('Primera Lectura')
        print("""Los bebés prematuros tienen una mayor probabilidad de convertirse en niños hiperactivos que los que nacen a término, 
según un estudio realizado en Dinamarca. Los investigadores concluyeron que los bebés que nacen entre las semanas 34 y
36 de gestación tienen 70% más de posibilidad de padecer trastorno por déficit de atención e hiperactividad (TDAH), una de
las causas más frecuentes de problemas escolares y sociales en la infancia. De acuerdo a los resultados del estudio, publicado
en la revista especializada Archives of Diseases in Childhood, los niños nacidos con menos de 34 semanas tienen un riesgo
tres veces mayor de contraer el TDAH.""")
        print()
        print("---------------------------------------------------------")
        print("Ingresa las letras a,b,c,d,e para responder las preguntas")
        print("---------------------------------------------------------")
        print()
        
        n1=input("-Primera pregunta-.\n\n¿Cuál es el tema del texto?\na) Un estudio en Dinamarca\nb) Problemas en la infancia\nc)  Niños enfermos\nd)  Problemas escolares y sociales de los infantes\ne)  Bebés prematuros y TDAH) \nR= ")
        respuesta.append(n1)
        print()
        n2=input("-Segunda pregunta-.\n\n¿Cuál es el título más adecuado para el texto? \na)Hiperactividad \nb)Un estudio sobre bebes \nc)Bebes prematuros,niños hiperactivos \nd)Bebés prematuros \ne)Gestación incompleta \nR= ")
        respuesta.append(n2)
        print()    
        n3=input("-Tercera pregunta-.\n\n¿Qué clase de progresión temática presenta el texto? \na) Mixta\nb) Compleja\nc) Continua\nd) Variada\ne) Variante \nR= ")
        respuesta.append(n3)
        print()
        n4=input("-Cuarta pregunta-.\n\n¿Qué clase de texto es según la ubicación de la idea principal? \na)Analizante \nb) Sintetizante \nc) Analizante-sintetizante \n d) Encuadrado \ne) Paralelo \nR= ")
        respuesta.append(n4)
        print()
        n5=input("-Quinta pregunta-.\n\nEs una idea incompatible con el texto: \na)  Los bebés prematuros podrían tener problemas escolares. \nb)  Un 30% de bebés prematuros no tendrán ningún tipo de problemas. \nc)  El TDAH es una enfermedad que se debe combatir a tiempo \nd)  Los bebés sietemesinos tienen mayores riesgos de contraer TDAH.\ne)  a y c \nR= ")
        respuesta.append(n5)
        print()
                                
        cont_lectura=0
        cont2=0
        for renglon in datos:
            respuestas_correctas.append(renglon)
        for i in range(len(respuesta)):
            if respuesta[i]==respuestas_correctas[i]:
                cont_lectura+=1
            else:
                cont2+=1
        print()
        encabezado="Materia estudiada,Nombre,Numero de aciertos\n"
        with open("../Thonny act/resultadosPrueba.csv","w") as outputFile:
            outputFile.write(encabezado)
            correctas=0
            nombre=input("Ingresa tu nombre ")
            lista_nombre.append(nombre)
            for i in range(len(respuestas_correctas)):
                resultados=""
                if respuestas_correctas[i]==respuesta[i]:
                    correctas+=1
            correctas=str(correctas)
            print()
            for i in range(len(lista_nombre)):
                print("\tMateria\t\tNombre\t\tNumero de aciertos")
                alumno=(f"\tLectura,\t{nombre},\t{correctas}")
                print("\t------------------------------------------------")
                print(f"\tLectura\t\t{nombre}\t\t{correctas}")
            outputFile.write(alumno)
        print()
        print(f"Respuestas correctas= {cont_lectura}")
        print(f"Respuestas incorrectas= {cont2}")
        
      
    elif opcion==2:
        print('Segunda Lectura')
        print(""" PROGRAMA DE ACOL PARA LA VACUNACIÓN VOLUNTARIA CONTRA
LA GRIPE
Como usted probablemente ya sabe, la gripe se propaga rápida y extensamente durante
el invierno. Los que la sufren pueden estar enfermos durante semanas.
La mejor manera de vencer a este virus es cuidar lo más posible la salud de
nuestro cuerpo. El ejercicio diario y una dieta rica en frutas y vegetales es lo más
recomendable para contribuir a que nuestro sistema inmunitario esté en buenas
condiciones para luchar contra el virus invasor.
ACOL ha decidido ofrecer a su personal la oportunidad de vacunarse contra la
gripe, como recurso adicional para evitar que este insidioso virus se extienda
entre nosotros. ACOL ha previsto que una enfermera lleve a cabo el programa
de vacunación dentro de la empresa en horas de trabajo, durante la mitad de la
jornada laboral de la semana del 17 de mayo. Este programa se ofrece
gratuitamente a todos los empleados de la empresa.
La participación es voluntaria. Los empleados que decidan utilizar esta oportunidad
deben firmar un impreso manifestando su consentimiento e indicando que no
padecen ningún tipo de alergia y que comprenden que pueden experimentar algunos
efectos secundarios sin importancia.
El asesoramiento médico indica que la inmunización no produce la gripe. No
obstante, puede originar algunos efectos secundarios como cansancio, fiebre ligera y
molestias en el brazo.
¿Quién debe vacunarse?
Cualquiera que esté interesado en protegerse del virus.
Esta vacunación está especialmente recomendada para las personas mayores
de 65 años y, al margen de la edad, para CUALQUIERA que padezca alguna enfermedad
crónica, especialmente si es de tipo cardíaco, pulmonar, bronquial o diabético. 

En el entorno de una oficina, TODAS LAS PERSONAS corren el riesgo de contraer
la enfermedad.
¿Quién no debe vacunarse?
Las personas que sean hipersensibles a los huevos, las que padezcan alguna enfermedad
que produzca fiebres altas y las mujeres embarazadas.
Consulte con su doctor si está tomando alguna medicación o si anteriormente
ha sufrido reacciones adversas a la vacuna contra la gripe.
Si usted quiere vacunarse durante la semana del 17 de mayo, por favor, avise a la jefa
de personal, Raquel Escribano, antes del viernes 7 de mayo. La fecha y la hora se fijarán
con- forme a la disponibilidad de la enfermera, el número de participantes en la
campaña y el horario más conveniente para la mayoría de los empleados. Si quiere
vacunarse para este invierno pero no puede hacerlo en las fechas establecidas, por
favor, comuníqueselo a Raquel. Quizá pueda fijarse una sesión de vacunación alternativa
si el número de personas es suficiente.
Para más información, contacte con Raquel en la extensión 5577

Raquel Escribano, directora del departamento de recursos humanos de una empresa
llamada ACOL, preparó la información que se presenta en esta página y en la anterior para
distribuirla entre el personal de la empresa ACOL.
Responde a las preguntas que se formulan a continuación, teniendo en cuenta la información
que aparece en las hojas de información. \n

""")
        respuestas_2=[]
        resp_correct_2=[]
        contador=0
        cont_inc=0
        print("Responder a,b,c,d, si contestas otra cosa se marcara mal y en minusculas \n")
        p1=input("Primera pregunta \n\n ¿Cuál de las siguientes afirmaciones describe una característica del programa de inmunización de ACOL contra la gripe? \na)Se darán clases de ejercicio físico durante el invierno \nb)La vacunación se llevará a cabo durante las horas de trabajo \nc)Se ofrecerá un pequeño bono a los participantes \nd)Un médico pondrá las inyecciones \nR== ")
        respuestas_2.append(p1)
        if p1=="b":
            print("Correcta")
            contador+=1
            respuestas_2.append(p1)
            p2=input("-Segunda pregunta- \n\n Esta hoja informativa sugiere que si uno quiere protegerse del virus de la gripe, la inyección de una vacuna de la gripe es... \na)Más eficaz que el ejercicio y una dieta saludable, pero más arriesgada \nb)Una buena idea, pero no un sustituto del ejercicio y la dieta saludable. \nc)Tan eficaz como el ejercicio y una dieta saludable y menos problemática. \nd)No es necesaria si se hace ejercicio y se sigue una dieta sana \n R== ")
            if p2=="b":
                print("Correcta")
                contador+=1
                respuestas_2.append(p1)
                p3=input("-Tercera pregunta-\n\nSegún la hoja informativa, ¿cuál de estos empleados de la empresa debería contactar con Raquel? \na)Ramón, del almacén, que no quiere vacunarse porque prefiere confiar en su sistema inmunológico natural.\nb)Julia, de ventas, que quiere saber si el programa de vacunación es obligatorio \nc)Alicia, de recepción, que querría vacunarse este invierno pero dará a luz dentro de dos meses\nd)Miguel, de contabilidad, al que le gustaría vacunarse pero tiene que salir de viaje la semana del 17 de mayo \nR== ")
                if p3=="d":
                    print("correcta")
                    contador+=1
                else:
                    print("Incorrecta")
                    cont_inc+=1
            else:
                print("Incorrecta")
                cont_inc+=1
        else:
            print("Incorrecta ")
            cont_inc+=1
        encabezado1="Materia estudiada,Nombre,Numero de aciertos\n"
        contador_respuestas=contador
        with open("../Thonny act/resultadosPrueba_2.csv","w") as outputFile:
            outputFile.write(encabezado1)
            lista_nombre2=[]
            nombre1=input("Ingresa tu nombre ")
            lista_nombre2.append(nombre1)
            alumno1=(f"\tLectura_2,\t{nombre1},\t{contador_respuestas}")
            for i in range(len(lista_nombre2)):
                print("\tMateria\t\tNombre\t\tNumero de aciertos")
                
                print("\t------------------------------------------------")
                print(f"\tLectura_2\t\t{nombre1}\t\t{contador_respuestas}")
            outputFile.write(alumno1)
        print()
        print(f"Respuestas correctas= {contador}")
        print(f"Respuestas incorrectas= {cont_inc}")
        
        
    else:
        print("Opción denegada")
            
def matematicas(opc,m,suma_e):
    cont=0
    cont2=0
    lista_nombre=[]
    lista_correctas=[]
    lista_incorrectas=[]
    nombre=input("Ingresa tu nombre ")
    print()
    lista_nombre.append(nombre)
    if opc==1:
        print(f"La matriz es: ")
        for renglon in range(len(m)):
            for columna in range(len(m[renglon])):
                print(m[renglon][columna], end='-')
            print()
        resp=int(input("Ingresa la suma de todos los elementos de la matriz generada "))
        if resp==suma_e:
            print("respuesta correcta")
            print()
            cont+=1
        else:
            cont2+=1
    elif opc==2:
        print(""" Mei-Ling se enteró de que el tipo de cambio entre el dólar de Singapur y el rand
sudafricano era de:
1 SGD = 4,2 ZAR
Mei-Ling cambió n dólares de Singapur en rands sudafricanos con este tipo de
cambio.
¿Cuánto dinero recibió Mei-Ling en rands sudafricanos?
""")
        n=random.randint(1,1000)
        print(f"cantidad a convertir {n}")
        a=n*4.2
        res=float(input("Ingresa la conversión "))
        if res==a:
            print("respuesta correcta\n")
            cont+=1
        else:
            print("respuesta incorrecta \n")
            cont2+=1
            
        print("""\n Al volver a Singapur, tres meses después, a Mei-Ling le quedaban n ZAR. Los cambió
en dólares de Singapur, dándose cuenta de que el tipo de cambio había cambiado a:
1 SGD = 4,0 ZAR
¿Cuánto dinero recibió en dólares de Singapur?  \n
""")
        b=random.randint(10,1000)
        print(f"Cantidad a convertir {b}")
        resp_1=b/4
        res_1=float(input("Ingresa la segunda conversión "))
        if res_1==resp_1:
            print("Respuesta correcta \n")
            cont+=1
        else:
            print("respuesta incorrecta \n")
            cont2+=1
    elif opc==3:
        print(""" La longitud del paso P es la
distancia entre los extremos posteriores de dos huellas consecutivas.
Para los hombres, la fórmula
n/p = 140
Da una relación aproximada entre n y P donde:
n = número de pasos por minuto, y
P = longitud del paso en metros. 
""")
        print("""----Primera pregunta---- \nSi se aplica la fórmula a la manera de caminar de Enrique y este da c pasos por
minuto, ¿cuál es la longitud del paso de Enrique? Muestra tus cálculos.""")
        c=random.randrange(140,1000,140)
        print()
        print(f"La cantidad de pasos dada es {c}")
        resp_2=c/140
        res_2=float(input("Ingresa la conversion "))
        if res_2==resp_2:
            print("respuesta_correcta")
            cont+=1
        else:
            cont2+=1
            print("respuesta incorrecta")
        print()
            
        print("""----Segunda pregunta----\nBernardo sabe que sus pasos son de m metros. El caminar de Bernardo
se ajusta a la fórmula.
Calcula la velocidad a la que anda Bernardo en metros por minuto 
""")
        m=random.randint(1,100)
        print(f"Pasos de bernardo de {m} metros")
        resp_3=m*140
        res_3=float(input("Ingresa la cantidad pedida "))
        if res_3==resp_3:
            print("respuesta correcta")
            cont+=1
        else:
            cont2+=1
            print("respuesta incorrecta")
        print()
            
    
    else:
        print("Opcion incorrecta")
        
    lista_correctas.append(cont)
    lista_incorrectas.append(cont2)
    print("\t\tNombre\t\tCorrectas\t\tIncorrectas")
    for dato in lista_nombre:
        print(f"\t\t{dato}", end=' ')
    for dato in lista_correctas:
        print(f"\t\t{dato}", end=' ')
    for dato in lista_incorrectas:
        print(f"\t\t{dato}", end=' ')
        
    print()
        
            
    
def matriz(r,c):
    matriz=[]
    for renglon in range(r):
        lista=[]
        for columna in range(c):
            dato=random.randint(0,50)
            lista.append(dato)
        matriz.append(lista)
    return matriz
def suma_elementos(m):
    total=0
    for renglon in m:
        for valor in renglon:
            total+=valor
    return total

intentos=0
menu=0
while menu!=3:
    print("-----------------------------")
    menu=int(input("Ingresa que quieres estudiar?\n-----------------------------\n1-Lectura \n2-Matematicas\n3-Salir \nR= "))
    if menu==1:
        print("------------------------")
        print("Escoge que quieres hacer\n------------------------\n1-Lectura \n2-Segunda Lectura")
        opcion=int(input("Ingresa que lectura quieres "))
        lectura(opcion)
    elif menu==2:
        print("\n Has escogido matematicas")
        print("------------------------------------------")
        print("Escoge que deseas realizar de matematicas\n------------------------------------------\n1-Suma de todos los elementos de una matriz \n2-Conversion de unidades \n3-Problemas matematicos")
        option=int(input("Ingresa tu respuesta "))
        renglon=3
        columna=3
        mtz=matriz(renglon,columna)
        suma_elementos(mtz)
        matematicas(option,mtz,suma_elementos(mtz))
    elif menu==3:
        print("\n Has decidido salir")
    else:
        print("Has ingresado una opción no aceptada\n Ingrese de nuevo")


