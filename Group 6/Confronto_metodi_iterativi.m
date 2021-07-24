n = input("Inserire ordine massimo: ");
S = {0,0,{},{{0,0},{0,0}}};
S = {S, S, S, S, S};
%Ciclo che genera 5 matrici di hilbert con ordini da n-4 a a n
%e 5 vettori con componenti la somma degli elementi sulle righe della
%matrice
for i = 1:5                     
   S{6-i}{1} = hilb(n+1-i);
   S{6-i}{2} = vec_sum(S{6-i}{1});
end

%Risolve i 5 sistemi lineari utilizzando i 4 medoti
for i = 1:5

    S{i}{3}{1} = gauss(S{i}{1}, S{i}{2});
    S{i}{3}{2} = cholesky(S{i}{1}, S{i}{2});    
    S{i}{4}{1} = jacobi(S{i}{1}, S{i}{2}, ones(1,size(S{i}{1},1)));    
    S{i}{4}{2} = gauss_seidel(S{i}{1}, S{i}{2}, ones(1,size(S{i}{1},1)));    

end

%Plotta gli errori del metodo di Jacobi e Gauss-Seidel a ogni passo di
%iterazionie
figure(1)
for i = 1:5
    subplot(3,2,i)
    y1 = (S{i}{4}{1}{2});
    plot(1:max(size(y1)),log(y1), "r-");
    hold on    

    y2 = (S{i}{4}{2}{2});
    plot(1:max(size(y2)),log(y2),"b-");
    hold on
    
    legend('Jacobi','Gauss-Seidel')
    ylabel("Errore scala log");
    xlabel("Passo di iterazione");
    title("Matrice di Hilbert di ordine " + (n-5+i));
end

%Plotta gli errori delle soluzioni di tutti e 4 i metodi in funzione 
%delle 5 matrici
figure(2)
errori = {0,0,0,0};
for i = 1:5
    soluzione = ones(1,n-5+i);
    for j = 1:2
        errori{j} = [errori{j}, norm(soluzione - S{i}{3}{j},2)/norm(soluzione,2)];
        errori{2+j} = [errori{2+j}, norm(soluzione - S{i}{4}{j}{1},2)/norm(soluzione, 2)];
    end    
end

colori = ["g*", "k*", "b*", "r*"];
for i = 1:4
    plot(n-5:n, log(errori{i}), colori(i));
    hold on
end
xlabel("Ordine matrice di Hilbert")
ylabel("Errore scala log")
legend('Gauss', 'Cholesky', 'Jacobi', 'Gauss-Seidel');



%Funzione che genera un vettore data una matrice, le cui i-esime componenti
%sono la somma degli elementi sulla i-esima riga della matrice
function b = vec_sum(A)
b = [];
    for i = 1:size(A,1)
        x = 0;
        for j = 1:size(A,1)
            x = x + A(i,j);
        end
        b = [b x];
    end
    
end

%Dato un sistema Ax = b dove A è triangolare superiore
%risolve il sistema applicando la backwards substitution
function x = backwards_substitution(A,b)
n = size(A,1);
x = 1:n;
x(n) = b(n)/A(n,n);
    for i = n-1:-1:1
        sum = 0;
        for j = i+1:n
            sum = sum + A(i,j)*x(j);
        end
        x(i) = (b(i) - sum)/A(i,i);
    end
end

function x = forward_substitution(A,b)
    n = size(A,1);
    x = 1:n;
    for i = 1:n
        x(i) = b(i);
        sum = 0;
        for j = 1:i-1
            sum = sum + A(i,j)*x(j);
        end
        x(i) = (x(i) - sum)/A(i,i);
    end

end

%dato un sistema Ax = B esegue l'algoritmo di eliminazione di Gauss
%trasformando il sistema in Ux = y, e richiamando infine
%la backwards substitution
function x = gauss(A, b)
    n = size(A,1);
    for k = 1:n-1
        highest = 0;
        for i = k:n
            val = abs(A(i,k));
            if highest<val
                highest = val;
                l = i;
            end
        end
    if highest == 0
        x = NaN;
        return
    end
    if l ~= k
        for j = k:n
           tmp = A(k,j);
           A(k,j) = A(i,j);
           A(i,j) = tmp;
        end
        tmp = b(k);
        b(k) = b(l);
        b(l) = tmp;
    end
    for i=k+1:n
        quot = A(i,k)/A(k,k);
        for j = k+1:n
            A(i,j) = A(i,j) - quot*A(k,j);
        end
        b(i) = b(i) - quot * b(k);
    end
    if A(n,n) == 0
        x = NaN;
        return
    end
    end
    x = backwards_substitution(A,b);
    
end

%Fattorizza la matrice A sfruttando la sua struttura, ottenendone
%la triangolare superiore per poi richiamare la forward e la
%la backwards substitution
function x = cholesky(A, b)
    n = size(A,1);
    for k = 1:n
        sum = 0;
        for p = 1:k-1
             sum = sum + (A(k,p) * A(k,p));
        end
        A(k,k) = sqrt(A(k,k) - sum);

        for i = k+1:n
            sum = 0;    
            for p = 1:k-1
            sum = sum + (A(i,p) * A(k,p));
            end
            
            A(i,k) = (A(i,k) - sum)/A(k,k);
        end
    end
    
    x = forward_substitution(A,b);
    x = backwards_substitution(A',x);
end

%scompone la matrice A nella sua diagonale, strettamente triangolare
%inferiore e strettamente triangolare superiore
function [D, B, C] = scomponi(A)
    n = size(A,1);
    B = zeros(n); 
    D = B;
    C = D;
    
    for i = 1:n
        D(i,i) = A(i,i);       
        for j = i+1:n
            C(i,j) = -1 * A(i,j);            
        end
        for j = 1:i-1
            B(i,j) = -1 * A(i,j);                        
        end
    end
end

%Verifica se la matrice di iterazione A è convergente alla soluzione x*
function x = convergenza(A)
    
    if max(eig(A)) < 1 %norma2 < 1 
        x = 1;
    else
        x = 0;

    end
end


function Dati = jacobi(A,b,x) %Spostamenti simultanei
    n = size(A,1);   
    Dati = {[],[]};  %Soluzione, errori a ogni passo di iterazione
    [D,B,C] = scomponi(A);
    if convergenza(inv(D)*(B+C))
        x1 = zeros(1,n);
        x2 = x1;
        for k = 1:500
            for i = 1:n
                sum = 0;
                for j = 1:i-1
                    sum = sum + A(i,j)*x1(j);
                end
                for j = i+1: n
                    sum = sum + A(i,j)*x1(j);            
                end
                x2(i) = (b(i) - sum)/A(i,i);
            end
            Dati{2} = [Dati{2}, norm(x-x2,'inf')];
            if Dati{2}(k)<0.01 || Dati{2}(k) == Inf %Termina il metodo se l'errore è molto piccolo o se diventa non convergente
                    Dati{2} = Dati{2}(1:end-1);
                    Dati{1} = x2;
                    return
            
            end
            x1 = x2;
            
        end
            Dati{1} = x2;
    else
        Dati{1} = Inf;
    end
end


function Dati = gauss_seidel(A,b, x) %Spostamenti successivi
    n = size(A,1);  
    Dati = {[],[]};    
    [D,B,C] = scomponi(A);
    if convergenza(inv(D-B)*C)
        x1 = zeros(1,n);
        for k = 1:500
            for i = 1:n
                sum = 0;
                for j = 1:i-1
                    sum = sum + A(i,j)*x1(j);
                end
                for j = i+1: n
                    sum = sum + A(i,j)*x1(j);            
                end
                x1(i) = (b(i) - sum)/A(i,i);
            end
                Dati{2} = [Dati{2}, norm(x-x1,'inf')];
            
            if Dati{2}(k)<0.01 || Dati{2}(k) == Inf
                Dati{2} = Dati{2}(1:end-1);
                Dati{1} = x1;
                return
            end
            
        end
        Dati{1} = x1;            
    else
        Dati{1} = Inf;
    end 
end


