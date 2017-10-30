
Public Class Form1

    Dim Buffer As String
    'Actualizar lista de puertos
    Private Sub btn_actualizar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_actualizar.Click
        bw_1.RunWorkerAsync()

    End Sub
    'Form Load
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Control.CheckForIllegalCrossThreadCalls = False
        btn_actualizar.PerformClick()
    End Sub
    'BW 1
    Private Sub bw_1_DoWork(ByVal sender As System.Object, ByVal e As System.ComponentModel.DoWorkEventArgs) Handles bw_1.DoWork
        cb_puertos.Items.Clear()
        txt_console.Text = txt_console.Text + "Actualizando Puertos..." + vbCrLf
        For Each sp As String In My.Computer.Ports.SerialPortNames
            Me.cb_puertos.Items.Add(sp)
        Next
        txt_console.Text = txt_console.Text + "Puertos Actualizados" + vbCrLf
    End Sub
    'Conectar Puerto
    Private Sub btn_conectar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_conectar.Click
        If sp_1.IsOpen <> True Then
            If cb_puertos.SelectedItem = Nothing Then
                MsgBox("Puerto no seleccionado!", MsgBoxStyle.Critical, "CkpDriver")
            Else
                txt_console.Text = txt_console.Text + "Conectando al puerto: " + cb_puertos.SelectedItem.ToString + vbCrLf
                sp_1.PortName = cb_puertos.SelectedItem.ToString
                Try
                    sp_1.Open()
                    txt_console.Text = txt_console.Text + "Puerto " + cb_puertos.SelectedItem.ToString + " conectado." + vbCrLf
                Catch ex As Exception
                    MsgBox("Error: " + ex.ToString, MsgBoxStyle.Critical, "CkpDriver")
                End Try
            End If
        Else
            MsgBox("El puerto ya esta abierto!", MsgBoxStyle.Information, "CkpDriver")
        End If
    End Sub
    'Cerrar Puerto
    Private Sub btn_desconectar_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_desconectar.Click
        Try
            sp_1.Close()
            txt_console.Text = txt_console.Text + "Puerto " + cb_puertos.SelectedItem.ToString + " desconectado" + vbCrLf
        Catch ex As Exception
            MsgBox("Error: " + ex.ToString, MsgBoxStyle.Critical, "CkpDriver")
        End Try
    End Sub
    'Enviar
    Private Sub btn_send_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_send.Click
        If sp_1.IsOpen Then
            Try
                If txt_send.Text <> "" Then
                    sp_1.Write(txt_send.Text)
                    txt_console.Text = txt_console.Text + "Texto Enviado" + vbCrLf
                Else
                    MsgBox("No hay texto para enviar!", MsgBoxStyle.Critical, "CkpDriver")
                End If
            Catch ex As Exception
                MsgBox("Error: " + ex.ToString, MsgBoxStyle.Critical, "CkpDriver")
            End Try
        Else
            MsgBox("Puerto cerrado!", MsgBoxStyle.Critical, "CkpDriver")
        End If
    End Sub
    'Timer para recibir data
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        If sp_1.IsOpen Then
            If sp_1.BytesToRead > 0 Then
                Buffer = sp_1.ReadLine
                txt_buf.Text = Buffer
            End If
        End If
    End Sub
End Class
