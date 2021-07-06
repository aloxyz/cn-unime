n = input("Inserisci ordine massimo: ")

%Inizializza matrice 4 * 3.
%A ogni riga corrisponde una norma, a ogni colonna il tipo di matrice.
%Ogni cella è un array di n-1 componenti che contiene l'indice di 
%di condizionamento di una matrice di ordine diverso
empty = zeros(1,n-1);
conds = {   empty, empty, empty;
            empty, empty, empty;
            empty, empty, empty;
            empty, empty, empty;};
        
for z = 2:n
    %Inizializza a ogni ciclo le tre matrici e le mette in un vettore
    r1 = rand(z, 1);
    V = vander(r1);
    H = hilb(z);

    r2 = rand((z-1), 1);
    D = diag(r1) + diag(r2, +1) + diag(r2, -1);
    
    M = {V, H, D};
    for j= 1:3
        conds{1,j}(z-1) = norm(inv(M{j}), 1)*norm(M{j}, 1);
		conds{3,j}(z-1) = norm(inv(M{j}), 2)*norm(M{j}, 2);		
		conds{2,j}(z-1) = norm(inv(M{j}), "fro")*norm(M{j}, "fro");
		conds{4,j}(z-1) = norm(inv(M{j}), "Inf")*norm(M{j}, "Inf");
    end
    
end

display("Norm 1")
    for j = 1:3
        conds{1,j}
    end

display("Norm 2")
    for j = 1:3
        conds{2,j}
    end
    
display("Norm Frobenius")
    for j = 1:3
        conds{3,j}
    end
    
display("Norm Inf")
    for j = 1:3
        conds{4,j}
    end
    
range = 2:n
figure(1);
plot(range,log(conds{1,1}), "r*");
hold on
plot(range,log(conds{1,2}), "b*");
plot(range,log(conds{1,3}), "y*");
legend('Vandermonde','Hilbert','Tridiagonale')
xlim([2,n])
ylim([1,log(max(max(cat(3, conds{1,1}, conds{1,2}, conds{1,3}))))])
ylabel("Indici di condizionamento");
xlabel("Ordine matrici");

for i=1:4
    subplot(2,2,i);
    plot(range,log(conds{i,1}), "r*");
    hold on
    plot(range,log(conds{i,2}), "b*");
    plot(range,log(conds{i,3}), "y*");
    legend('Vandermonde','Hilbert','Tridiagonale')
    xlim([2,n])
    ylim([1,log(max(max(cat(3, conds{i,1}, conds{i,2}, conds{i,3}))))])
    ylabel("Indici di condizionamento");
    xlabel("Ordine matrici");
    if i == 1
        title("Norma 1")
    elseif i==2
        title("Norma 2")
    elseif i==3
        title("Norma Frobenius")
    else
        title("Norma Inf")
   
    end
end

