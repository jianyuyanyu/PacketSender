# Introduzione

![Packet Sender Logo](screenshots/packetsender_banner.png)

### [https://packetsender.com](https://packetsender.com/)


*Leggi questo in altre lingue: [English](README.md), [Español](README.es.md), [Deutsch](README.de.md), [Français](README.fr.md), [Italiano](README.it.md), [简体中文](README.zh.md).*


[![Downloads](https://img.shields.io/github/downloads/dannagle/PacketSender/total.svg)](https://packetsender.com/download)

Packet Sender è un'utilità open source che permette di inviare e ricevere pacchetti TCP, UDP e SSL (TCP crittografato), nonché richieste HTTP/HTTPS e la generazione di pannelli. Il ramo principale supporta ufficialmente Windows, Mac e Linux desktop (con Qt). Altri distributori possono ricompilare e ridistribuire Packet Sender. Packet Sender è gratuito e rilasciato sotto licenza GPL v2 o successiva. Può essere utilizzato sia per scopi commerciali che personali. Se trovi utile l'applicazione, considera di donare o sponsorizzare per far continuare lo sviluppo.



# Indice dei contenuti
* [Sponsor](#sponsors)
    * Visita [IWL.com](https://www.iwl.com/)
    * Visita [NagleCode.com](https://dannagle.com/)
    * Visita [Eletiope.com](http://eletiope.com/)
    * Visita [John Huntington](https://www.controlgeek.net/)
* [GUI](#gui)
* [Generatore di traffico intenso (GUI)](#udptraffic)
* [Rete](#network)
* [Download](#downloads)
* [App Mobile per iOS](#ios)
* [Supporto](#support)
* [Calcolatore di subnet IPv4](#subnetcalculator)
* [Wake-On-LAN / Magic Packet](#wakeonlan)
* [Packet Sender Cloud](#cloud)
* [Modalità portatile](#portable)
* [Macro e risposte intelligenti](#smartresponses)
* [TCP e SSL persistenti](#persistent)
* [Richieste HTTP/HTTPS](#http)
* [Generatore di pannelli](#panelgen)
* [Interfaccia a riga di comando](#cli)
* [Generatore di traffico intenso (CLI)](#cliintensetraffic)
* [Compilazione di Packet Sender](#building)




<a id="sponsors"></a>
## Sponsor

Packet Sender desidera ringraziare i seguenti sponsor.

[![IWL](screenshots/iwl_logo.png)](https://www.iwl.com/)
<br>IWL è un'azienda californiana che produce dispositivi per il networking informatico.
<br><br><br>

[![NagleCode](screenshots/naglecode-logo400.png)](https://dannagle.com)
<br>NagleCode è un editore di software e uno studio di sviluppo.
<br><br><br>

[![Eletiope](screenshots/eletiope_logo400.png)](http://eletiope.com)
<br>Eletiope installa impianti di illuminazione, audiovisivi e stanze immersive per mostre e musei, nonché per showroom aziendali.
<br><br><br>

[John Huntington](https://www.controlgeek.net/)
<br>Autore, consulente, educatore, ingegnere del suono, fotografo pluripremiato e storm chaser.
<br><br><br>

[Vuoi che il tuo nome/logo sia elencato qui?](https://github.com/sponsors/dannagle)



<a id="support"></a>
## Supporto

* Twitter/X: [@NagleCode](https://x.com/NagleCode)
* I forum si trovano su: [Discussioni GitHub](https://github.com/dannagle/PacketSender/discussions).
* Email: [Contatto Packet Sender](https://packetsender.com/contact)
* Collegati con me su [LinkedIn](https://www.linkedin.com/in/dannagle/)

*NOTA:* Prova (temporaneamente) a disattivare il firewall se hai problemi su Windows.



<a id="downloads"></a>
# Download

## Download per desktop
Le versioni ufficiali di Packet Sender possono essere scaricate su [PacketSender.com](https://packetsender.com/download). Alcuni siti ridistribuiscono Packet Sender.

![Windows Logo](screenshots/winlogo150.png) ![Mac Logo](screenshots/maclogo150.png) ![Linux Logo](screenshots/Tux150.png)



<a id="ios"></a>
## App Mobile per iOS
Packet Sender per iOS è completamente nativo, richiede il minimo indispensabile di permessi e non raccoglie alcun dato. Questo è software che ti rispetta. Grazie per aver supportato questo progetto.

La versione iOS si trova sull'[Apple App Store](https://apps.apple.com/app/id1558236648#?platform=iphone)

[![Packet Sender iOS](screenshots/packetsender-ios-traffic-log-ascii.png)](https://apps.apple.com/app/id1558236648#?platform=iphone)

<a id="gui"></a>
# GUI

Packet Sender è identico su tutte le versioni desktop. L'unica differenza è il tema che si adatta al sistema operativo.

![Packet Sender screenshot](screenshots/ps_GUI.png)

1. Un pacchetto ha un nome, un indirizzo di destinazione (i nomi di dominio vengono risolti automaticamente appena prima dell'invio), porta e dati associati.
2. Nella tabella c'è l'elenco dei pacchetti salvati. Puoi fare doppio clic per modificare direttamente i campi in questa tabella.
3. In basso a destra ci sono lo stato e le porte dei server UDP, TCP e SSL. Cliccandoci sopra si attivano o disattivano i protocolli. Packet Sender supporta l'associazione a un numero qualsiasi di porte.
4. C'è anche un pulsante per alternare l'IP. Cliccandolo passa da IPv4 (predefinito) a IPv6 o IP personalizzato.

### Note generali
* Un valore di "0" per il re-invio significa che è un pacchetto a colpo singolo.
* Durante il re-invio di pacchetti apparirà un pulsante per annullare tutti i re-invii.
* Controlla il tuo firewall. Windows blocca aggressivamente i server basati su TCP. Packet Sender funzionerà comunque se il firewall lo blocca, ma non potrà ricevere pacchetti TCP non sollecitati.
* È possibile inviare una risposta opzionale. La stessa risposta viene usata per TCP, UDP e SSL.
* Per l'invio IPv6 è necessario anche l'ID di ambito (scope ID).
* Packet Sender supporta la notazione mista ASCII e HEX:
    * Fai doppio clic su uno dei due campi per aprire l'editor multilinea
    * \XX viene tradotto in XX in esadecimale
    * \n, \r, \t vengono tradotti in 0A, 0D e 09
    * I numeri HEX sono separati da spazi
        * Il campo HEX tenterà di interpretare altri delimitatori comuni (virgole, due punti come in Wireshark, punti e virgola, " 0x", ecc.) e di correggerli automaticamente. È molto tollerante agli errori.
        * È supportato anche un flusso continuo di HEX. Se il numero di byte è dispari, Packet Sender aggiungerà uno zero all'inizio e correggerà automaticamente.
    * Esempio ASCII: hello world\r
    * Esempio HEX: 68 65 6c 6c 6f 20 77 6f 72 6c 64 0d
    * Puoi salvare un pacchetto direttamente dal registro del traffico. Ti verrà chiesto un nome e l'indirizzo sorgente e la porta verranno invertiti per tua comodità.
    * Puoi anche caricare un file direttamente nel campo HEX. Il campo HEX supporta l'invio fino a 10.922 byte. Il limite teorico per l'invio da riga di comando è 200 MB.


## Scorciatoie da tastiera / Hotkey

I campi in alto possono essere navigati con CTRL+1, CTRL+2, ecc. fino a CTRL+8 (pulsante Invia). Su Mac il tasto è Command.

Le hotkey e i campi sono:
* CTRL + 1 = Nome
* CTRL + 2 = ASCII
* CTRL + 3 = HEX
* CTRL + 4 = Indirizzo
* CTRL + 5 = Porta
* CTRL + 6 = Ritardo re-invio
* CTRL + 7 = Selezione protocollo
* CTRL + 8 = Invia (esegue)


Alcune note:
* I campi sono collegati alla rispettiva hotkey indipendentemente dalla selezione del protocollo.
* Quando navighi sull'opzione TCP/UDP/SSL puoi usare i tasti su/giù o i caratteri t/u/s/h per selezionare.
* Se vuoi automatizzare con hotkey (usando strumenti come [AutoHotKey](https://www.autohotkey.com/)), potresti voler disattivare "Ripristina sessione precedente".



<a id="network"></a>
# Funzionalità di rete

## Impostazioni di base
All'avvio Packet Sender attiva di default i server UDP, TCP e SSL su porte casuali (mostrate come pulsanti in basso a destra). Puoi associare un numero qualsiasi di porte (se il sistema operativo lo permette), usando numeri separati da virgola. Ad esempio `0, 1000, 2000` assocerà una porta casuale e le porte 1000 e 2000.

![Basic Network Settings](screenshots/basic_network_settings.png)

Il pulsante UDP ora mostra 3 porte associate. Una di esse è casuale.

![Bound UDP Example](screenshots/bound_udp_example.png)

L'altra impostazione è rispondere a tutte le richieste con una replica. Puoi anche far sì che la risposta sia una macro. C'è un campo per digitare la replica (o caricare un pacchetto salvato).


## Impostazioni aggiuntive UDP/TCP/SSL
Di default Packet Sender si associa a qualsiasi indirizzo IPv4. In questa sezione delle impostazioni puoi associare a qualsiasi IPv6 oppure a un indirizzo IP specifico.

Associare a un indirizzo specifico è molto utile quando ci sono più schede di rete e vuoi forzare il traffico (ad esempio pacchetti broadcast) su una specifica interfaccia.

![Bound UDP Example](screenshots/additional_network_settings.png)

Alcuni protocolli si aspettano che il server invii dati prima che il client invii (come molti servizi telnet). Questo flusso di lavoro può essere abilitato con "Ricevi prima di inviare".

Se hai un dispositivo lento (ad esempio un server embedded con un processore debole), puoi abilitare "500 ms di ritardo dopo la connessione". Questo darà al server lento il tempo di avviare il gestore.

## IPv4, IPv6, IP personalizzato

I server integrati di Packet Sender sono configurati per supportare IPv4 o IPv6 ma non entrambi contemporaneamente. Per i client, la GUI e la CLI di Packet Sender passeranno senza problemi tra le due modalità all'invio (può essere necessario lo scope ID per IPv6). Clicca sul pulsante IPv4 / IPv6 in basso a destra per alternare tra le due.

Nelle impostazioni puoi anche forzare i server di Packet Sender ad associarsi a un indirizzo IP personalizzato. Questo è molto utile su sistemi con più schede di rete o configurazioni IP complesse. Packet Sender genererà un errore se gli viene chiesto di associarsi a un indirizzo inesistente.

![IP Specific binding](screenshots/ip-specific-binding.png)


<a id="subnetcalculator"></a>
## Calcolatore di subnet IPv4

Packet Sender include un calcolatore di subnet integrato. Si trova nel menu Strumenti.
![Packet Sender Subnet Calc](screenshots/packetsender_subnetcalc.PNG)

* La finestra di log (sezione inferiore) mostrerà gli indirizzi IPv4 e IPv6 non loopback trovati sul tuo computer.
* Sul lato sinistro inserisci l'indirizzo IPv4 nel campo IP.
* Sul lato sinistro inserisci la subnet in notazione X.X.X. o /XX
* I risultati del calcolo sono sul lato destro.
* Il campo sottostante è un controllo rapido per verificare se un IPv4 è all'interno di una delle tue subnet.


<a id="wakeonlan"></a>
## Wake-On-LAN / Magic Packet

Wake-On-LAN (o WOL) è un protocollo che dice ai computer di svegliarsi dal sonno. Viene attivato da un pacchetto broadcast con dati speciali basati sull'indirizzo MAC del destinatario. Per maggiori informazioni, [consulta Wikipedia](https://en.wikipedia.org/wiki/Wake-on-LAN).

Packet Sender include un generatore WOL integrato. Si trova nel menu Strumenti.

![WOL Tool](screenshots/wake_on_lan_screenshot.png)

Compila le opzioni e la GUI principale verrà riempita con i dati corretti per il formato WOL.

![WOL results](screenshots/wake_on_lan_results_screenshot.png)

Ci sono anche opzioni CLI per generare e inviare pacchetti WOL

```text
packetsender --wol f8:23:66:30:e5:30
Invio broadcast Wake-On-LAN al target: F8:23:66:30:E5:30 sulla porta 7
UDP (60360)://255.255.255.255:7 ff ff ff ff ff ff f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30
```

<a id="wakeonlan"></a>
## Wake-On-LAN / Pacchetto Magico

Wake-On-LAN (o WOL) è un protocollo che permette di risvegliare i computer dalla modalità sospensione.  
Viene attivato inviando un pacchetto broadcast contenente dati speciali basati sull'indirizzo MAC del computer target.  
Per maggiori informazioni, [consulta la pagina Wikipedia](https://en.wikipedia.org/wiki/Wake-on-LAN).

Packet Sender include un generatore WOL integrato. Si trova nel menu **Strumenti**.

![Strumento WOL](screenshots/wake_on_lan_screenshot.png)

Compila le opzioni richieste e l'interfaccia principale verrà automaticamente popolata con i dati corretti nel formato WOL.

![Risultati WOL](screenshots/wake_on_lan_results_screenshot.png)

Sono disponibili anche opzioni da riga di comando (CLI) per generare e inviare pacchetti WOL.

```text
packetsender --wol f8:23:66:30:e5:30
Sending broadcast Wake-On-LAN to target: F8:23:66:30:E5:30 on port 7
UDP (60360)://255.255.255.255:7 ff ff ff ff ff ff f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30 f8 23 66 30 e5 30
```

## Client e Server SSL

Packet Sender supporta l'instaurazione di connessioni crittografate tramite SSL.  
Questa funzionalità è disponibile sia nell'interfaccia grafica (GUI) che da riga di comando.

Packet Sender include OpenSSL per l'utilizzo su Windows. Su Mac e Linux, Packet Sender utilizzerà le librerie SSL native del sistema.

![Packet Sender Direct TCP](screenshots/packetsender_ssl.PNG)

Note su SSL:
* La negoziazione del certificato avviene immediatamente durante la connessione.
* Per impostazione predefinita, Packet Sender ignora tutti gli errori SSL (certificato scaduto, nome host errato, certificato autofirmato, ecc.).
* Packet Sender riporta i progressi della negoziazione del certificato nel log del traffico.
* Packet Sender indica nel log del traffico l'algoritmo di crittografia utilizzato (ad esempio AES 128).

Packet Sender include un certificato interno "Snake Oil" da utilizzare come server su Windows. Il certificato e la chiave si trovano nella stessa posizione dei file di pacchetti e delle impostazioni.

_Nota: Modificando i percorsi dei certificati nelle Impostazioni, viene sovrascritto anche il certificato snake-oil._

In caso di errore SSL, Packet Sender lo riporta nel log del traffico. Se l'impostazione è di proseguire comunque (predefinita), la negoziazione della crittografia continua. In caso contrario, la connessione termina con un fallimento.

![Packet Sender Direct TCP Scaduto](screenshots/packetsender_expired_ssl.png)

## Multicast (Sperimentale)

Il supporto multicast di Packet Sender si attiva tentando di inviare a un indirizzo multicast IPv4 o dal sottomenu multicast. La funzionalità è attualmente sperimentale e presenta i seguenti problemi noti.

* Packet Sender abbandona il supporto IPv6 quando si unisce a un gruppo multicast.
* Tale abbandono persiste finché non si riaprono le impostazioni o non si tenta di inviare a un indirizzo IPv6.
* Su reti Wi-Fi, a volte occorrono fino a 20 secondi affinché l'unione al gruppo multicast diventi effettiva.
* Packet Sender non dispone di logica per riunirsi automaticamente a un gruppo multicast in caso di riavvio dello switch o altri errori comuni.

Non esiste supporto per multicast IPv6, sebbene sia nella roadmap di sviluppo. Gli sponsor interessati al supporto multicast IPv6 sono invitati a contattarmi.

<a id="udptraffic"></a>

## Generatore di Traffico UDP (Sperimentale)

Quando il normale sistema di invio non è sufficiente, è possibile inviare un flusso intenso di pacchetti a un IP target per verificare se il dispositivo riesce a gestirlo.  
Questa funzione si trova nella barra degli strumenti della GUI: _Strumenti → Generatore di Traffico Intenso_

Si prega di notare che questa funzionalità è sperimentale e le metriche visualizzate non sono state completamente testate. Per un test più accurato, si consiglia di utilizzare la versione CLI di questo strumento.

![Associazione IP specifica](screenshots/udp-traffic-sending.PNG)

# Funzionalità di Packet Sender

<a id="cloud"></a>
## Packet Sender Cloud

I set di pacchetti possono essere salvati, recuperati e condivisi rapidamente utilizzando il servizio gratuito [Packet Sender Cloud](https://cloud.packetsender.com/).  
Il cloud può essere utilizzato anche per visualizzare pubblicamente e distribuire i propri pacchetti (tramite un URL) per collaborazioni, tutorial, utenti finali, ecc. Packet Sender può importare set di pacchetti pubblici tramite URL pubblici.

Esistono diversi motivi per farlo:
* Mantenere tutti i tuoi pacchetti pronti per recuperarli rapidamente quando installi una nuova copia di Packet Sender
* Passare velocemente tra set di pacchetti quando lavori su progetti diversi
* Condividere un account di login (è permesso) per la generazione collaborativa di set di pacchetti
* Avere una pagina pubblica dei tuoi set di pacchetti in modo che altri possano trovarli e importarli rapidamente

![Importazione Packet Sender Cloud](screenshots/cloud-import.png)

Se stai pubblicando un'API di rete, mantenere una pagina cloud pubblica è **molto più semplice** rispetto a descrivere in modo laborioso (IP, porta, tipo, ecc.) i pacchetti agli utenti. Inoltre, aggiornare quella pagina è facile.

Maggiori informazioni sono disponibili qui:  
https://cloud.packetsender.com/help


<a id="portable"></a>
## Modalità Portatile

Packet Sender dispone di una modalità "portatile". All'avvio, cerca il file `portablemode.txt` e popola eventuali file di impostazioni mancanti nella directory di esecuzione.  
Questi file sono: `packets.ini`, `ps_settings.ini`, `ps.key` e `ps.pem`.  
È anche possibile mantenere alcuni file in modalità portatile e altri nella posizione standard rimuovendo `portablemode.txt`.

### DLL che possono essere rimosse in modalità solo-console (portatile)
Se non hai bisogno dell'interfaccia grafica, puoi rimuovere queste DLL:
- Qt6Svg.dll
- Qt6Widgets.dll
- Qt6Gui.dll
- opengl32sw.dll
- D3Dcompiler_47.dll
- directory iconengines
- directory imageformats
- directory styles

Nota: le DLL con il carattere `+` nel nome possono creare problemi con il copia-incolla da riga di comando di Windows se non vengono racchiuse tra virgolette `"`.

### DLL che possono essere rimosse se non servono connessioni sicure
Se non utilizzi SSL, puoi rimuovere queste DLL:
- libcrypto-1_1-x64.dll
- libssl-1_1-x64.dll


La directory di esecuzione su Windows è la stessa in cui si trova il file `.exe`.

Per gli utenti Mac, la directory di esecuzione si trova in:  
`PacketSender.app/Contents/MacOS`  
Se vengono trovati file INI in quella posizione, verranno utilizzati al posto di `%APPDATA%` o `Library/Application Support`.


<a id="smartresponses"></a>
## Smart Responses (Risposte Intelligenti)

Packet Sender supporta fino a 5 risposte intelligenti.

Per abilitare questa funzione, vai su _File → Impostazioni_ nella barra degli strumenti della GUI.  
Passa alla scheda _Smart Responses_ e attiva la casella **Send a Smart Response**.

![Packet Sender Smart Reply](screenshots/packetsender_smartreply.PNG)

* Packet Sender confronta il pacchetto ricevuto utilizzando l'encoding da te scelto
* Packet Sender traduce l'encoding prima di inviare la risposta
* Gli encoding disponibili sono:
    * Mixed ASCII — Il metodo standard di Packet Sender per codificare ASCII insieme a caratteri non stampabili
    * HEX — La normale codifica esadecimale di Packet Sender


## Macro

Packet Sender supporta le seguenti macro durante l'invio delle risposte:

* `{{DATE}}` — Invia la data corrente nel formato "yyyy-mm-dd"
* `{{TIME}}` — Invia l'ora corrente nel formato "hh:mm:ss ap"
* `{{UNIXTIME}}` — Invia il timestamp epoch corrente
* `{{COUNTER}}` — Invia un contatore incrementale per ogni pacchetto che lo utilizza. Parte da 1 all'avvio.
* `{{RANDOM}}` — Invia un numero casuale compreso tra 0 e 32767 (32-bit) o 2147483647 (64-bit) a seconda della build (l'installer predefinito Windows è 32-bit, Mac è 64-bit)
* `{{UNIQUE}}` — Invia una stringa casuale generata tramite UUID interno

Packet Sender sostituisce le macro con i valori reali prima dell'invio.


<a id="persistent"></a>
## Connessioni TCP e SSL Persistenti

Packet Sender supporta connessioni TCP e SSL persistenti tramite una finestra GUI separata.  
Si attiva tramite una casella di spunta nella finestra principale o dalle Impostazioni.

![Packet Sender Direct TCP e SSL](screenshots/packetsender_direct_tcp.PNG)

### Note sulle connessioni TCP e SSL persistenti:
* È possibile creare un numero qualsiasi di connessioni persistenti
* I pacchetti salvati in precedenza possono essere caricati dal menu a tendina
* Sono disponibili le viste "Raw" e "ASCII". La vista ASCII è utile per risolvere problemi con dati non stampabili nella vista raw
* Il traffico viene comunque salvato nel log principale
* È possibile caricare un file nella connessione persistente (potrebbe essere utile disattivare il logging in questo caso)
* Il timer in basso a sinistra parte non appena viene inviato/ricevuto un pacchetto valido. Si ferma quando la connessione viene chiusa
* È possibile aggiungere automaticamente un carriage return (\r) premendo Invio (utile per menu a riga di comando su TCP/SSL). Packet Sender ricorda lo stato precedente della casella \r
* Le connessioni in ingresso al server avviano automaticamente la finestra GUI separata
* Durante il reinvio, il pacchetto della connessione persistente viene trasferito nella nuova finestra. Cliccando su "Resending(1)" si annulla il reinvio

Le connessioni persistenti **non** sono supportate da riga di comando.


<a id="http"></a>
# HTTP/HTTPS POST & GET

Packet Sender supporta l'invio di richieste POST/GET tramite HTTP e HTTPS.  
Il menu a tendina del protocollo include: HTTP GET, HTTP POST, HTTPS GET, HTTPS POST.  
Quando si seleziona HTTP(S), i campi si aggiornano in: Nome, Request, Address, Data (se POST), pulsante Generate Data (se POST), Load File (se POST).

## Invio di richieste HTTP/HTTPS GET/POST
![](/screenshots/ps_http_getfields.PNG)
* Seleziona HTTP(S) GET o POST dal menu a tendina del protocollo
* Nel campo *Address* inserisci dominio o IP
* Nel campo *Request* aggiungi il percorso URL (se necessario)
* Nel campo *Port* il valore predefinito è 80 per HTTP e 443 per HTTPS
* Spunta *Persistent TCP* per visualizzare i dati del server in modo più chiaro (gli header HTTP vengono rimossi automaticamente)

**Puoi anche incollare un URL completo nel campo Request: Packet Sender lo analizzerà e compilerà automaticamente gli altri campi.**

### Per le richieste POST:
* Puoi inserire manualmente i dati nel campo *Data*  
  Formato: `chiave=valore`  
  Per più parametri: `chiave=valore&chiave=valore&chiave=valore`
* Oppure clicca sul pulsante *Generate Data*

<img src="/screenshots/ps_http_datagenerator.PNG" width="400" height="284">

* Inserisci Chiave e Valore, poi clicca **+**
* Puoi aggiungere più parametri con il pulsante +
* Rimuovi un parametro con il pulsante X
* Una volta terminato, clicca OK: i dati verranno generati nel campo Data

### Per aggiungere credenziali di autenticazione:

<img src="/screenshots/ps_http_authgenerator.PNG" width="800" height="339">

* Vai su File → Impostazioni → HTTP
* Spunta *Generate Auth Header*
* Inserisci *Host*, *UN/Client ID* e *PW/Access*
* Clicca su *HTTP Auth Header* per generare l'header di autenticazione


<a id="panelgen"></a>
# Generatore di Pannelli

Packet Sender supporta la creazione di pannelli di controllo.  
I pannelli sono composti da pulsanti a cui sono associati script (pacchetti). Cliccando un pulsante si eseguono i pacchetti collegati.

<img src="/screenshots/ps_panel_1.PNG" width="400" height="358">

## Caricamento di un pannello
I pannelli possono essere creati in due modi:
* Cliccando su **Pannelli** nella barra degli strumenti e scegliendo *Load Starter Panel* o *Empty Panel Project*  
  (*Load Starter Panel* carica il pannello impostato come starter; se non ce n'è uno, apre un progetto vuoto)
* Selezionando 2 o più pacchetti salvati e cliccando sul pulsante **Generate Panel** (appare solo con più pacchetti selezionati)

È possibile avviare Packet Sender in modalità solo-pannello con il pannello starter usando l'opzione da riga di comando `--starterpanel`

![](/screenshots/ps_panel_generate.PNG)


## Programmazione di un pannello
Per iniziare a programmare i pulsanti, apri un pannello e passa alla modalità Editing.  
Una volta aperto il progetto, controlla il pulsante in basso a destra: se dice "Viewing" sei in modalità visualizzazione. Cliccalo per passare a "Editing".

### Programmazione dei pulsanti
Lo script di un pulsante contiene il nome del pacchetto da inviare.

<img src="/screenshots/ps_panel_2.PNG" width="400" height="360">

È possibile associare più pacchetti a un pulsante inserendo un nome per riga.

<img src="/screenshots/ps_panel_5.PNG" width="400" height="358">

Il generatore supporta l'inserimento di un ritardo tra pacchetti multipli con:  
`delay:_numero_di_secondi_`

<img src="/screenshots/ps_panel_4.PNG" width="400" height="359">

Supporta anche il caricamento di un nuovo pannello con:  
`panel:_numero_id_pannello_`

<img src="/screenshots/ps_panel_8.PNG" width="400" height="358">


### Aggiunta di file / URL
È possibile creare pulsanti che aprono file locali o URL.

In modalità Editing, clicca sul **+** in basso a destra.
* Per file: copia il file (tasto destro → Copia) e incollalo nel campo _URL o File_
* Per URL: incolla l'indirizzo (deve iniziare con http:// o https://)

![](/screenshots/ps_panel_7.PNG)

Dopo aver incollato, ti verrà chiesto di dare un nome al pulsante.  
I pulsanti appaiono in fondo al pannello.

In modalità Editing puoi modificarli o eliminarli (tasto **X**).  
In modalità Viewing cliccandoli si aprirà l'URL nel browser predefinito o il file con l'applicazione associata.

![](/screenshots/ps_panel_6.PNG)


### Modifica e salvataggio del pannello
In modalità Editing appare una barra con menu: File, Export, Settings, Help.  
Da qui puoi salvare, esportare, importare, caricare progetti e modificare il pannello corrente.

Dal menu Settings puoi:
* Set Panel Name — rinominare il progetto
* Set Panel ID — cambiare l'ID (sovrascrive un pannello con lo stesso ID)
* Starter Panel — impostare questo come pannello di avvio
* Delete Panel — eliminare un pannello esistente  
  (Nota: i pulsanti e gli script restano visibili fino alla chiusura del pannello)


# DTLS

Al momento DTLS è supportato solo nell'interfaccia grafica su Windows.  
Su altri sistemi operativi è possibile abilitarlo compilando da sorgente con Qt6.

## Panoramica
Questa funzionalità aggiunge il protocollo DTLS (Datagram Transport Layer Security) con interfaccia grafica per configurare e gestire connessioni DTLS, inclusa verifica del server e persistenza della sessione.

## Funzionalità principali

### Finestra principale
![Main Window](screenshots/main_window.png)
- **Cipher Suites**: menu a tendina per selezionare la suite di cifratura desiderata
- **Server Common Name**: campo per inserire il common name del server (verifica lato client)
- **Persistent Session**: opzione per salvare la chiave di sessione dopo il primo handshake
- **Optional Server Verification**: attiva la verifica bidirezionale durante l'handshake
- **DTLS Server Port**: pulsante per definire la porta del server DTLS

#### Immagini aggiuntive:
![Cipher Suites Dropdown](screenshots/cipher_suites.png)
![Persistent Connection](screenshots/persistant_dtls.jpg)
![Server Port](screenshots/server_ports.png)

### Finestra Impostazioni

#### Scheda Network
![Network Tab](screenshots/settings.png)
- **Send Simple Acknowledge**: invia un semplice acknowledgement
- **Enable DTLS Server**: attiva il server DTLS e seleziona la porta
- **Certificates and Keys**: caricamento certificati e chiavi (simile a SSL)

#### Scheda Smart Responses
![Smart Responses Tab](screenshots/settings_2.png)
- Le Smart Responses funzionano anche su protocollo DTLS

## Integrazione Wireshark

### Connessione normale
![Regular Connection](screenshots/wireshark_simple_session.png)

### Connessione persistente
![Persistent Connection](screenshots/wireshark_persistent_connection.png)


<a id="cli"></a>
# Riga di comando

Packet Sender può essere utilizzato da riga di comando.

Su Windows usa l'estensione `.com` (`packetsender.com`) per la modalità CLI.  
Puoi anche usare semplicemente `packetsender` senza estensione.  
Usare `.exe` avvia invece la GUI.

![Packet Sender CLI screenshot](screenshots/packetsender_command_line.png)

Su Linux (e Mac) segue lo stile tipico delle utility: opzioni lunghe (--version) e corte (-v), ordine libero.  
Le ultime tre opzioni sono posizionali: indirizzo, porta, dati (opzionali se si usa un pacchetto salvato).

```text
packetsender --help
Usage: packetsender [options] address port data
Packet Sender is a Network UDP/TCP/SSL/HTTP Test Utility by NagleCode
See https://PacketSender.com/ for more information.

Options:
  -h, --help                Mostra aiuto sulle opzioni
  --help-all                Mostra aiuto completo (inclusi opzioni Qt)
  -v, --version             Mostra versione
  -q, --quiet               Modalità silenziosa. Stampa solo i dati ricevuti
  -x, --hex                 Interpreta i dati come hex (default per TCP/UDP/SSL)
  -a, --ascii               Interpreta come mixed-ascii (default per HTTP e GUI)
  -A, --ASCII               Interpreta come puro ASCII (nessuna traduzione \xx)
  -l, --listen              Ascolta invece di inviare
  -r, --response <ascii>    Risposta in modalità server (supporta macro)
  -w, --wait <ms>           Attende fino a <ms> per una risposta (0 = non aspettare)
  -f, --file <path>         Invia contenuto del file (max 10 MiB UDP, 100 MiB TCP/SSL)
  -b, --bind <port>         Porta di bind (default 0 = dinamica)
  -6, --ipv6                Forza IPv6
  -4, --ipv4                Forza IPv4
  -B, --bindip <IP>         Bind su IP specifico
  -t, --tcp                 Invia TCP (default)
  -s, --ssl                 Invia SSL ignorando errori
  -S, --SSL                 Invia SSL e si ferma in caso di errore
  -u, --udp                 Invia UDP
  --http <http>             Invia HTTP (GET o POST)
  -n, --name <name>         Invia pacchetto salvato con quel nome
  --wol <mac>               Invia Wake-On-LAN a <mac> (opzionale <port>)
  --bps <bps>               Traffico intenso: bit per secondo
  --num <number>            Traffico intenso: numero di pacchetti
  --rate <Hertz>            Traffico intenso: frequenza
  --usdelay <microseconds>  Traffico intenso: ritardo tra invii
  --max                     Traffico intenso: velocità massima possibile

Arguments:
  address                   Indirizzo/URL destinazione
  port                      Porta / dati POST
  data                      Dati da inviare
```
## Esempio CLI

La CLI segue lo stesso formato su Windows, Linux e Mac.

Il formato è:
`packetsender [options] address port data`

```text
packetsender -taw 500 mirrors.xmission.com 21 "USER anonymous\r\nPASS chrome@example.com\r\n"
TCP (65505)://mirrors.xmission.com:21 55 53 45 52 20 61 6e 6f 6e 79 6d 6f 75 73 0d 0a 50 41 53 53 20 63 68 72 6f 6d 65 40 65 78 61 6d 70 6c 65 2e 63 6f 6d 0d 0a
Response Time:5:51:37.042 pm
Response HEX:32 32 30 2D 57 65 6C 63 6F 6D 65 20...
Response ASCII:220-Welcome to XMission Internet...
```

## Esempio CLI per ascoltare pacchetti (Modalità Server)

Utilizza le opzioni di bind esistenti per configurare il server.
- `-b` per la porta
- `-B` per l'IP
- `-t` / `-u` / `-s` per TCP, UDP o SSL
- `-r` per inviare una risposta (supporta macro in ASCII)

Binding su porta dinamica usando TCP

```text
packetsender -l
TCP Server started on 0.0.0.0:52567
Use ctrl+c to exit server.

From: 127.0.0.1, Port:52568
Response Time:2024-06-04 19:01:53.198
Response HEX:48 65 6C 6C 6F 
Response ASCII:Hello

From: 127.0.0.1, Port:52569
Response Time:2024-06-04 19:02:24.063
Response HEX:57 6F 72 6C 64 
Response ASCII:World
```

Binding sulla porta 8080 usando UDP

```text
packetsender -l -u -b 8080
UDP Server started on 0.0.0.0:8080
Use ctrl+c to exit server.

From: ::ffff:127.0.0.1, Port:49500
Response Time:2024-06-04 19:04:28.890
Response HEX:48 65 6C 6C 6F 20 55 44 50 20 50 61 63 6B 65 74 
Response ASCII:Hello UDP Packet
```

Binding sulla porta 8080 usando UDP con risposta contenente l'ora corrente

```text
packetsender -l -u -b 8080 -r "{{TIME}}"
Loading response packet.
UDP Server started on 0.0.0.0:8080
Use ctrl+c to exit.

From: ::ffff:127.0.0.1, Port:59594
Response Time:2024-06-05 20:48:18.180
Response HEX:68 65 6C 6C 6F 20 70 61 63 6B 65 74 20 73 65 6E 64 65 72 
Response ASCII:hello packet sender

From: You (Response), Port:59594
Response Time:2024-06-05 20:48:18.182
Response HEX:30 38 3a 34 38 3a 31 38 20 70 6d 
Response ASCII:08:48:18 pm
```


Binding su IP 192.168.86.26, porta 54321 usando SSL

```text
packetsender -l -s -B 192.168.86.26 -b 54321 
Binding to custom IP 192.168.86.26
Listening for SSL packets in server mode. 
SSL Server started on 192.168.86.26:54321
Use ctrl+c to exit server.

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Encrypted with AESGCM(256)

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Authenticated with RSA

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Peer cert issued by 

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.726
Error/Info:Our Cert issued by SnakeOil

From: 192.168.86.26, Port:52588
Response Time:2024-06-04 19:11:30.747
Response HEX:43 6F 6F 6C 20 53 53 4C 
Response ASCII:Cool SSL
```

## Esempi di binding su porta e IP personalizzato, IPv4 o IPv6

La riga di comando di Packet Sender può effettuare il bind su porte personalizzate per forzare le modalità IPv4/6 o utilizzare più schede di rete (NIC) tramite l'opzione `-B`.

```text
packetsender -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
packetsender -taw 3000 192.168.0.201 5005 "Hello\r"
packetsender -B 192.168.0.200 -taw 3000 192.168.0.201 5005 "Hello\r"
packetsender -B fe80::a437:399a:3091:266a%ethernet_32769 -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
packetsender -B fe80::a437:399a:3091:266a -taw 3000 fe80::c07b:d517:e339:5a08 5005 "Hello\r"
```

## Esempio CLI usando SSL e ignorando gli errori

La riga di comando offre l'opzione di ignorare o interrompere in caso di errori SSL. Il comportamento predefinito è ignorare.

* Usa l'opzione `-s` per inviare tramite SSL e ignorare gli errori.
* Usa l'opzione `-S` per inviare tramite SSL e interrompere in caso di errori.

```text
packetsender -saw 500 expired.packetsender.com 443 "GET / HTTP/1.0\r\n\r\n"
SSL Error: The certificate has expired
SSL (54202)://expired.packetsender.com:443 47 45 54 20 2f 20 48 54 54 50 2f 31 2e 30 0d 0a 0d 0a
Cipher: Encrypted with AES(128)

Response Time:3:24:55.695 pm
Response HEX:48 54 54 50 2f 31 2e 31 20 34 32 31 20 0d 0a 53 65 72 76 65 72 3a 20 6e 67 69 6e 78 2f 31 2e 31 30 2e 30 20 28 55 62 75 6e 74 75 29 0d
Response ASCII:HTTP/1.1 421 \r\nServer: nginx/1.10.0 (Ubuntu)\r
```

## Esempio CLI usando HTTP

Nota: questo utilizza i pacchetti predefiniti integrati.

```text
packetsender --name "HTTPS POST Params"
packetsender --http GET "https://httpbin.org/get"
packetsender --http POST "https://httpbin.org/post" "{}"
```

<a id="cliintensetraffic"></a>

## Esempio con CLI Intense Traffic Generator

Il generatore di traffico intenso da riga di comando funziona in modo molto simile alla versione GUI, ma è un po' più accurato, offre maggiori opzioni di controllo (e maggiore intensità!).

Vedi di seguito alcuni esempi di utilizzo. Nota che questi calcoli sono "Best Effort". Funziona bene, ma picchi del processore o vari problemi di rete possono alterare i risultati. Il threading non è in tempo reale e non è particolarmente intelligente nei tentativi di compensazione.

* Reinvia "My Awesome Packet" a una frequenza di 20 Hz
* Reinvia "My Awesome Packet" a 2000 baud (bps)
* Reinvia "My Awesome Packet" il più velocemente possibile
* Reinvia "My Awesome Packet" con un ritardo di 2000000 microsecondi tra ogni pacchetto

**Nota: Su Windows, usa la build ".com", quindi in ogni esempio dovrai scrivere `packetsender.com` invece di `packetsender`**

```text
packetsender --rate 20 --name "My Awesome Packet"
packetsender --bps 2000 --name "My Awesome Packet"
packetsender --rate 0 --name "My Awesome Packet"
packetsender --usdelay 2000000 --name "My Awesome Packet"
```


<a id="building"></a>
# Compilazione di Packet Sender

L'unica dipendenza è Qt SDK

## Compilazione di Packet Sender per Windows e Mac
1. Scarica l'installer di Qt da https://www.qt.io/download-open-source/
1. Lascia che installi MinGW se non hai già un compilatore.
1. Apri il progetto `PacketSender.pro`
1. Compila!

Le versioni per Windows e Mac sono state compilate con Qt 5.12. Packet Sender supporta anche Qt 6, tuttavia non supporta cmake.

## Compilazione di Packet Sender per Linux
Ecco la sequenza di comandi per Ubuntu 16.04. Adattala alla tua distribuzione Linux. Packet Sender non richiede librerie aggiuntive oltre al Qt SDK standard. Mi è stato segnalato che ci sono problemi di compilazione con Fedora stock. Se qualche esperto di Fedora ha suggerimenti, fatemelo sapere e aggiungerò le istruzioni.

Se ti senti avventuroso, sentiti libero di compilare dal branch master.  
Contiene l'ultima build stabile.  
Il branch development dovrebbe probabilmente essere evitato.

```bash
sudo apt-get update
sudo apt-get install qt5-default build-essential
wget https://github.com/dannagle/PacketSender/archive/(Version).tar.gz
tar -xzvf (Version).tar.gz
cd PacketSender-(Version)/src
qmake PacketSender.pro
make
```

Per eseguire usa:
```text
./PacketSender
```

Se non si avvia, potrebbe essere necessario renderlo eseguibile

```text
chmod a+x PacketSender
```

# Miglioramenti/Richieste

Manca una funzionalità? Puoi [assumermi per aggiungerla a Packet Sender](https://packetsender.com/enhancements).

# Legale / Conformità

La licenza è GPL v2 o successive. [Contattami](https://packetsender.com/contact) se richiedi una licenza diversa.
Alcune distribuzioni di Packet Sender possono utilizzare [OpenSSL](https://www.openssl.org/).
La VPAT più aggiornata [può essere trovata](vpat_2.4_packetsender.pdf) in questo repository.

# Copyright

Packet Sender è stato scritto da [Dan Nagle](https://dannagle.com/) ed è pubblicato da &copy; NagleCode, LLC   -  [@NagleCode](https://x.com/NagleCode) - [PacketSender.com](https://packetsender.com)
