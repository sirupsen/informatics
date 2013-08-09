program grader;

uses birthday;

procedure fail(s: string);
begin
    writeln(stderr, s);
    halt(1);
end;

var
    R, N, i: longint;
    X1, Y1, X2, Y2: array of Longint;
    f: text;
    answer: longint;

begin
    assign(f, 'birthday.in');
    {$I-} reset(f); {$I+}
    if IOResult <> 0 then
        fail('Failed to open input file.');

    readln(f, R);
    readln(f, N);

    setlength(X1, N);
    setlength(Y1, N);
    setlength(X2, N);
    setlength(Y2, N);

    for i := 0 to N-1 do
        readln(f, X1[i], Y1[i], X2[i], Y2[i]);
    close(f);

    answer := pieces(R, N, X1, Y1, X2, Y2);

    writeln(answer);
end.
