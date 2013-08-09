program grader;

uses citizen;

procedure fail(s: string);
begin
    writeln(stderr, s);
    halt(1);
end;

var
    N, i: longint;
    P, Q: array of Longint;
    f: text;
    answer: longint;

begin
    assign(f, 'citizen.in');
    {$I-} reset(f); {$I+}
    if IOResult <> 0 then
        fail('Failed to open input file.');

    readln(f, N);
    setlength(P, N);
    setlength(Q, N);

    for i := 0 to N-1 do
        readln(f, P[i], Q[i]);
    close(f);

    answer := countries(N, P, Q);

    writeln(answer);
end.
