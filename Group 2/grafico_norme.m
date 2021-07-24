%Crea i grafici delle norme dei vettori caricando i tabulati di punti da file


figure(1)
legenda = [];
dati = ["norma 1", "norma 2", "norma inf"];
colori = ['r', 'b', 'g'];
for i = 1:3
    if isfile(dati(1))
        A = readmatrix(dati(i));
        plot(A(:,1), A(:,2), colori(i));
        hold on
        legenda = [legenda, dati(i)];
    end
end

legend(legenda);


