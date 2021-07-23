%Crea i grafici delle funzioni caricando i tabulati di punti da file


figure(1)
legenda = [];
dati = ["dati1", "dati2", "dati3"];
funzioni = ["1/(1+25*(x*x))", "x/(1+(x*x))", "|x|"];
colori = ['r', 'b', 'g'];
for i = 1:3
    if isfile(dati(1))
        A = readmatrix(dati(i));
        plot(A(:,1), A(:,2), colori(i));
        hold on
        legenda = [legenda, funzioni(i)];
    end
end

legend(legenda);


