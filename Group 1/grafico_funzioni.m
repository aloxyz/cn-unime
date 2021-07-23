%Crea i grafici delle funzioni caricando i tabulati di punti da file


figure(1)
legenda = [];
if isfile("dati1")
    A = readmatrix('dati1');
    plot(A(:,1), A(:,2), 'r');
    hold on
    legenda = [legenda, "1/(1+25*(x*x))"];
end

if isfile("dati2")
    A = readmatrix('dati2');
    plot(A(:,1), A(:,2), 'b');
    hold on
    legenda = [legenda, "x/(1+(x*x))"];
end

if isfile("dati3")
    A = readmatrix('dati3');
    plot(A(:,1), A(:,2), 'g');
    legenda = [legenda, "|x|"];
end

legend(legenda);


